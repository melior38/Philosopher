/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:39:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/26 09:39:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

long long	get_time_in_ms(void)
{
	struct timeval    tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	make_mutex(t_rules *rules)
{
	int i;

	i = rules->number_of_philosophers;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->fork[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->write_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->death_lock), NULL))
		return (1);
	return (0);
}

void	set_philo(t_rules *rules, int actual_philo)
{
	t_philosopher *philo;

	philo = rules->philosopher;
	if (rules->number_of_philosophers == 1)
	{
		philo[actual_philo].right_fork_id = actual_philo;
		return ;
	}
	if( actual_philo == 0)
		philo[actual_philo].left_fork_id = rules->number_of_philosophers - 1;
	else
		philo[actual_philo].left_fork_id = actual_philo - 1;
	philo[actual_philo].right_fork_id = actual_philo;
	philo[actual_philo].last_meal = 0;
	philo[actual_philo].philo_id = (actual_philo + 1);
	philo[actual_philo].rules = rules;
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		set_philo(rules, i);
		i++;
	}
}

void	print_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		printf("philo number %d\n\n", i + 1);
		printf("left_fork_id = [%d]\n", rules->philosopher[i].left_fork_id);
		printf("right_fork_id = [%d]\n", rules->philosopher[i].right_fork_id);
		printf("x_meal = [%d]\n", rules->philosopher[i].x_meal);
		printf("philo_id = [%d]\n\n", rules->philosopher[i].philo_id);
		i++;
	}
}

void	print_action(t_rules *rules, int philo_id, char *print, int color)
{
	pthread_mutex_lock(&(rules->write_lock));
	// check si la variable dead est set et tout ce qui pourrait faire arreter le print
	if (color == 0)
		printf("%s", CYAN);
	else if (color == 1)
		printf("%s", RED);
	else if (color == 2)
		printf("%s", GREEN);
	else if (color == 3)
		printf("%s", PURPLE);
	printf("%lldms ", get_time_in_ms() - rules->prog_debut);
	printf("%d ", philo_id);
	printf("%s\n", print);
	printf("%s", RESET);
	pthread_mutex_unlock(&(rules->write_lock));
}