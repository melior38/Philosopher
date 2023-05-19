/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:48:07 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 13:48:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "philosopher.h"
#include <time.h>
#include <math.h>

pthread_mutex_t mutex;

void	*roll_dice() 
{
	pthread_mutex_lock(&mutex);
	int value = (rand() % 6) + 1;
	int *result = malloc(sizeof(int));
	*result = value;
	pthread_mutex_unlock(&mutex);
	// printf("dice roll {%d}\n", value);
	return ((void*) result);
}

int	philo(pthread_t *th, int nmb_of_dice_rolling)
{
	int	**th_tab = malloc(sizeof(int) * nmb_of_dice_rolling + 5);
	// printf("nb of input [%d]\n", nmb_of_dice_rolling);
	// int	*th_tab;

	// printf("nmb_of_dice_rolling [%d]\n", nmb_of_dice_rolling);
	for (int i = 0; i < nmb_of_dice_rolling; i++)
	{
		if (pthread_create(th + i, NULL, &roll_dice, NULL) != 0)
			{
				perror("create problem:");
				exit (1);
			}
	}
	// printf("on est al ou pas\n");
	// printf("on est hors de la fonction");
	for (int i = 0; i < nmb_of_dice_rolling; i++)
	{
		if (pthread_join(th[i], (void**) &th_tab[i]) != 0)
			{
				perror("join / wait problem:");
				exit (1);
			}
	}
	// printf("on est hors de la fonction");
	// printf("on est al ou pas\n");
	// printf("on est hors du thread omg et regarde sa [%d]\n", *th_tab);
	// free(th_tab);
	print_int_tab(th_tab, nmb_of_dice_rolling);
	return (0);
}