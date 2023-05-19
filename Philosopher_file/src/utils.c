/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:18:48 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 18:18:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "philosopher.h"
#include <time.h>
#include <math.h>

int	ft_atoi(char *str)
{
	int	neg;
	int	res;
	int	i;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

int	is_number(int nb)
{
	if (nb <= '0' && nb >= '9')
		return (1);
	return (0);
}

int	av_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (is_number(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	input_check(char **av, int ac)
{
	int ret;

	ret = 0; 
	if (av_check(av[1]))
		ret = -1;
	if (av_check(av[2]))
		ret = -1;
	if (av_check(av[3]))
		ret = -1;
	if (av_check(av[4]))
		ret = -1;
	if (ac == 6 && av_check(av[5]) == 1)
		ret = -1;
	if (ret == -1)
		perror("invalid argument, make sure to only input numbers");
	return (ret);
}

int	make_rules(t_rules *rules, char **av, int ac)
{
	if (input_check(av, ac));
		return 1;
	rules->number_of_philosophers = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->N_O_T_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		rules->N_O_T_each_philosopher_must_eat = -1;
	return (0);
}