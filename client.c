/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:59 by sbenouat          #+#    #+#             */
/*   Updated: 2023/02/21 14:59:44 by sbenouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	*ctob(char c, pid_t pid)
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

void	stob(char *b)
{
	while (*b != '\0')
	{
		printf("%s\n", ctob(*b));
		b++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{

	}
}
