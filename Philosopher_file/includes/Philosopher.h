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

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philosopher {
	int					left_fork_id;
	int					right_fork_id;
	pthread_t			thread;
	long long			last_meal;
	struct s_rules		*rules;

}				t_philosopher;

typedef struct s_rules {
	int					number_of_philosophers; 
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					dieded;
	int					N_O_T_each_philosopher_must_eat;
	long long			prog_debut;
	t_philosopher		philosopher[250];
	pthread_mutex_t		fork[250];
	pthread_mutex_t		write_lock;
	pthread_mutex_t		death_lock;
}				t_rules;

int				ft_atoi(char *str);
int				is_number(char nb);
int				av_check(char *av);
int				input_check(char **av, int ac);
int				make_rules(t_rules *rules, char **av, int ac);
void			make_philo_thread(t_rules *rules);
long long		get_time_in_ms(void);
void			set_philo(t_rules *rules, int actual_philo);
int				make_mutex(t_rules *rules);
void			print_action(t_rules *rules, int philo_id, char *print);
// int		philo(pthread_t *th, int nmb_of_dice_rolling);
// void	*roll_dice();
// void	print_int_tab(int **th_tab, int i);

#endif