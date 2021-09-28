/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:34:38 by bkael             #+#    #+#             */
/*   Updated: 2021/09/16 16:35:03 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		num;

	i = 0;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if (num > 2147483647)
			return (-1);
		i++;
	}
	if (nptr[i] != '\0')
		return (-1);
	return (num);
}

int	ft_init_arg(t_philo *philo, int argc, char **argv)
{
	philo->number_of_philo = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_eats = ft_atoi(argv[5]);
	else
		philo->number_of_eats = 0;
	if (argc == 6 && philo->number_of_eats < 1)
		return (1);
	if (philo->number_of_philo < 1 || philo->die < 60 || philo->sleep < 60
		|| philo->eat < 60 || philo->number_of_philo > 200)
		return (1);
	return (0);
}

void	ft_init_persons(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philo)
	{
		philo->persons[i].i = i;
		philo->persons[i].left = i;
		philo->persons[i].right = i % 2;
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}
