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

#include "philosopher.h"

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

void	print_action(t_rules *rules, int philo_id, char *print)
{
	pthread_mutex_lock(&(rules->write_lock));
	// check si la variable dead est set et tout ce qui pourrait faire arreter le print
	printf("%lld ", get_time_in_ms() - rules->prog_debut);
	printf("philo[%d] ", philo_id);
	printf("%s\n", print);
	pthread_mutex_unlock(&(rules->write_lock));
}