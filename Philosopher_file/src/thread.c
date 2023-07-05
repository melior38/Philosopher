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
	pthread_mutex_lock(&rules->fork[philo->left_fork_id]);
	print_action(rules, philo->philo_id, "has taken a secund fork", 0);
	pthread_mutex_lock(&rules->death_lock);
	print_action(rules, philo->philo_id, "is eating", 2);
	// printf("what's the problem ? [%d]\n", philo->philo_id);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&rules->death_lock);
	dynamic_sleep(rules->time_to_eat, rules);
	pthread_mutex_unlock(&rules->fork[philo->right_fork_id]);
	pthread_mutex_unlock(&rules->fork[philo->left_fork_id]);
}

void	*routine(void *arg)// tu veut lui passez la struct ducoup
{
	t_philosopher	*philo;
	t_rules			*rules;

	philo = (t_philosopher *)arg;
	rules = philo->rules;
	if (philo->philo_id % 2)
		usleep(15000);
	while (rules->dieded == 0)
	{
		philo_eats(philo);
		if (rules->meal_finished != 0)
			break ;
		print_action(rules, philo->philo_id, "is sleeping", 0);
		dynamic_sleep(rules->time_to_sleep, rules);
		print_action(rules, philo->philo_id, "is thinking", 3);
	}
	return (NULL);
}

void	end_thread(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->philosopher[i].thread , NULL))
		{
				perror("thread joining problem:");
				exit (1);
		} 
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
}

void	death_checker(t_rules *rules)
{
	t_philosopher	*philo;
	int				i;
	
	philo = rules->philosopher;
	while (rules->meal_finished != rules->N_O_T_each_philosopher_must_eat || 
			rules->N_O_T_each_philosopher_must_eat == -1)
	{
		i = -1;
		while (++i < rules->number_of_philosophers && rules->dieded != 0)
		{
			pthread_mutex_lock(&rules->death_lock);
			if (time_diff(philo[i].last_meal, get_time_in_ms()) <= rules->time_to_die)
			{
				print_action(rules, philo[i].philo_id, "died", 1);
				rules->dieded = 1;
			}
			pthread_mutex_unlock(&rules->death_lock);
		}
		i = 0;
		while (i < rules->number_of_philosophers && rules->N_O_T_each_philosopher_must_eat != -1 
				&& philo[i].x_meal >= rules->N_O_T_each_philosopher_must_eat)
			i++;
		if (i == rules->number_of_philosophers)
			rules->meal_finished = 1;
	}
}

void	make_philo_thread(t_rules *rules)
{
	int	i;

	i = 0;
	rules->prog_debut = get_time_in_ms();
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&(rules->philosopher[i].thread) , NULL, &routine, rules->philosopher + i))
		{
				perror("thread create problem:");
				exit (1);
		}
		i++;
	}
	death_checker(rules);
	end_thread(rules);
// 	return (0);
}