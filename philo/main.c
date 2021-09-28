/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:26:24 by bkael             #+#    #+#             */
/*   Updated: 2021/09/14 16:27:03 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		philo;

	if (argc < 5 || argc > 6)
		return (ft_putendl_fd("Invalid number of arguments", 2));
	if (ft_init_arg(&philo, argc, argv))
		return (ft_putendl_fd("Invalid arguments", 2));
	philo.persons = malloc(sizeof(t_person) * philo.number_of_philo);
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.number_of_philo);
	if (!philo.persons || !philo.forks)
		return (ft_putendl_fd("Malloc error", 2));
	ft_init_persons(&philo);
	return (0);
}
