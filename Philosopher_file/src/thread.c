/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:32 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 17:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	philo_eats(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&rules->fork[philo->right_fork_id]);
	print_action(rules, philo->philo_id, "has taken a fork", 0);
	if (philo->left_fork_id == philo->right_fork_id)
	{
		pthread_mutex_unlock(&rules->fork[philo->right_fork_id]);
		return ;
	}
	else
		pthread_mutex_lock(&rules->fork[philo->left_fork_id]);
	print_action(rules, philo->philo_id, "has taken a fork", 0);
	print_action(rules, philo->philo_id, "is eating", 2);
	pthread_mutex_lock(&rules->death_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&rules->death_lock);
	pthread_mutex_lock(&rules->write_lock);
	philo->x_meal += 1;
	pthread_mutex_unlock(&rules->write_lock);
	dynamic_sleep(rules->time_to_eat, rules);
	pthread_mutex_unlock(&rules->fork[philo->right_fork_id]);
	pthread_mutex_unlock(&rules->fork[philo->left_fork_id]);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_rules			*rules;

	philo = (t_philosopher *)arg;
	rules = philo->rules;
	if (philo->philo_id % 2)
		usleep(15000);
	while (rules->dieded == 0)
	{
		pthread_mutex_lock(&rules->write_lock);
		if (rules->meal_finished != 0)
		{
			pthread_mutex_unlock(&rules->write_lock);
			break ;
		}
		pthread_mutex_unlock(&rules->write_lock);
		philo_eats(philo);
		if (philo->left_fork_id == philo->right_fork_id)
			break ;
		print_action(rules, philo->philo_id, "is sleeping", 0);
		dynamic_sleep(rules->time_to_sleep, rules);
		print_action(rules, philo->philo_id, "is thinking", 3);
		if (rules->number_of_philosophers == 1)
			break ;
	}
	return (NULL);
}

int	end_thread(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->philosopher[i].thread , NULL))
				return (1);
		i++;
	}
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&rules->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->write_lock);
	pthread_mutex_destroy(&rules->death_lock);
	return (0);
}

void	death_checker(t_rules *rules)
{
	t_philosopher	*philo;
	int				i;
	
	philo = rules->philosopher;
	while (1)
	{
		i = -1;
		while (++i < rules->number_of_philosophers && rules->dieded == 0)
		{
			pthread_mutex_lock(&rules->death_lock);
			if (time_diff(philo[i].last_meal, get_time_in_ms()) > rules->time_to_die)
			{
				print_action(rules, philo[i].philo_id, "died", 1);
				pthread_mutex_lock(&rules->write_lock);
				rules->dieded = 1;
				pthread_mutex_unlock(&rules->write_lock);
			}
			pthread_mutex_unlock(&rules->death_lock);
		}
		i = 0;
		pthread_mutex_lock(&rules->write_lock);
		while (i < rules->number_of_philosophers && rules->N_O_T_each_philosopher_must_eat != -1 
				&& philo[i].x_meal >= rules->N_O_T_each_philosopher_must_eat)
			i++;
		pthread_mutex_unlock(&rules->write_lock);
		if (i == rules->number_of_philosophers || rules->dieded == 1)
		{
			pthread_mutex_lock(&rules->write_lock);
			rules->meal_finished = 1;
			pthread_mutex_unlock(&rules->write_lock);
			break ;
		}
	}
}

int	make_philo_thread(t_rules *rules)
{
	int	i;

	i = 0;
	rules->prog_debut = get_time_in_ms();
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&(rules->philosopher[i].thread) , NULL, &routine, rules->philosopher + i))
				return (1);
		i++;
	}
	death_checker(rules);
	if (end_thread(rules))
		return (1);
	return (0);
}