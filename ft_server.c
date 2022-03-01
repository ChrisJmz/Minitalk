/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:13:20 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 18:16:47 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	struct sigaction sa;

	(void)av;
	if (ac == 1)
	{
		ft_printf("PID: %d\n", getpid());
	}
	sa.sa_flags = SA_SIGINFO;
	pause();
	return (0);
}
