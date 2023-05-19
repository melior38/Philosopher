/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:48:04 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 13:48:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_rules {
	int	number_of_philosophers; 
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	N_O_T_each_philosopher_must_eat;
}				t_rules;

int		ft_atoi(char *str);
int		is_number(int nb);
int		av_check(char *av);
int		input_check(char **av, int ac);
int		make_rules(t_rules *rules, char **av, int ac);
int		make_philo_thread(t_rules *rules);
// int		philo(pthread_t *th, int nmb_of_dice_rolling);
// void	*roll_dice();
// void	print_int_tab(int **th_tab, int i);

#endif