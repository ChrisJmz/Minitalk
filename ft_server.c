/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:13:20 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/07 13:43:04 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	message(int sig)
{
	static char chr = 0x00;
	static int	size = 7;

	if (sig == SIGUSR1)
	{
		chr += (1 << size);
		size--;
	}
	else if (sig == SIGUSR2)
		size--;
	if (size < 0)
	{
		write(1, &chr, 1);
		if (!chr)
			write(1, "\n", 1);
		chr = 0x00;
		size = 7;
	}
}

int main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, message);
	signal(SIGUSR2, message);
	while (1)
		pause();
	return (0);
}
