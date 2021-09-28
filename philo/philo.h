/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:23:41 by bkael             #+#    #+#             */
/*   Updated: 2021/09/14 16:26:08 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_person
{
	int	i;
	int	left;
	int	right;
}				t_person;

typedef struct s_philo
{
	int				number_of_philo;
	int				die;
	int				eat;
	int				sleep;
	int				number_of_eats;
	t_person		*persons;
	pthread_mutex_t	*forks;
}				t_philo;

int		ft_strlen(char *s);
int		ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		ft_init_arg(t_philo *philo, int argc, char **argv);
void	ft_init_persons(t_philo *philo);

#endif