/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:59 by sbenouat          #+#    #+#             */
/*   Updated: 2023/02/13 16:05:01 by sbenouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	*ctob(char c)
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
			rslt[j] = '1';
		else
			rslt[j] = '0';
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

int	main(void)
{
	printf("Voici le PID : %d\n", getpid());
	stob("SALAM");
	return (0);
}
