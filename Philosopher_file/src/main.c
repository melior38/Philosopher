/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:40 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 17:04:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"


int	main(int ac, char **av)
{
	t_rules	rules;
	
	if (ac < 5 || ac > 6)
	{
		perror("wrong amount of argument");
		return (1);
	}
	if (make_rules(&rules, av, ac))
		return (1);
	if (make_philo_thread(&rules))
	{
		printf("error occurred with either creating/joining thread\n");
		return (1);
	}
	return (0);
}