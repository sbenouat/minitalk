/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:59 by sbenouat          #+#    #+#             */
/*   Updated: 2023/02/24 15:07:32 by sbenouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	*ctob(char c, pid_t pid)
{
	int		i;
	int		j;
	char	*rslt;

	j = 0;
	i = 7;
	rslt = calloc(8, 1);
	while (i >= 0)
	{
		i--;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
			//rslt[j] = '1';
		else
			kill(pid, SIGUSR2);
			//rslt[j] = '0';
		j++;
	}
	return (rslt);
}

void	stob(char *s, pid_t pid)
{
	while (*s != '\0')
	{
		ctob(s, pid);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		stob(av[2], av[1]);
	}
}
