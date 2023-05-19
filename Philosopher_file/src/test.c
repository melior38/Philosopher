/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:50:13 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 13:50:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "philosopher.h"
#include <time.h>
#include <math.h>

// probablement une bonne idee de penser a faire un liste pour philo ne serait-ce que pour
// pouvoir parcourir un tableau de value sans avoir a de casser la tete sur la taille de 
// la liste.

void	print_int_tab(int **th_tab, int i)
{
	int n = 0;

	while (n < i)
	{
		printf("dice roll nmb:[%d] result:[%d]\n", n + 1, *th_tab[n]);
		free(th_tab[n]);
		th_tab[n] = NULL;
		n++;
	}
		free(th_tab);
}

int	main(int ac, char **av)
{
	// pthread_mutex_t mutex;
	int	nmb_of_dice_rolling = atoi(av[1]);
	pthread_t th[nmb_of_dice_rolling];
	
	srand(time(NULL));
	if (ac != 2)
		exit(1);
	philo(th, nmb_of_dice_rolling);
	
	// printf("lol le makefile fonctionne\n");
	// philo();
	return (0);
}
