/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:20:10 by sbenouat          #+#    #+#             */
/*   Updated: 2023/02/22 18:44:27 by sbenouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libftprintf/ft_printf.h"

int	main(void)
{
	ft_printf("Voici le PID : %d\n", getpid());
	return (0);
}
