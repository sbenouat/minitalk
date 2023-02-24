/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:59 by sbenouat          #+#    #+#             */
/*   Updated: 2023/02/24 16:22:17 by sbenouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	*ctob(char c)
{
	int		i;
	int		j;
	char	*rslt;

	j = 0;
	i = 7;
	rslt = ft_calloc(8, 1);
	while (i >= 0)
	{
		i--;
		if (c & (1 << i))
			// kill(pid, SIGUSR1);
			rslt[j] = '1';
		else
			// kill(pid, SIGUSR2);
			rslt[j] = '0';
		j++;
	}
	return (rslt);
}

void	stob(char *s)
{
	while (*s != '\0')
	{
		ctob(*s);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		stob(av[1]);
	}
}
