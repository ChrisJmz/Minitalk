/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:33:37 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/16 18:09:58 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_error(void)
{
	ft_printf("\033[0;31m[ERROR]\033[0m: Unable to reach the server\n");
	exit(0);
}

static int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] == '\0')
		ft_error();
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_send(int pid, char *msg)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = ft_strlen(msg) - 1;
	while (i++ <= size)
	{
		j = 8;
		while (j-- > 0)
		{
			if ((msg[i] >> j) & 1)
			{
				if (kill(pid, SIGUSR1))
					ft_error();
			}
			else if (!((msg[i] >> j) & 1))
			{
				if (kill(pid, SIGUSR2))
					ft_error();
			}
			usleep(10000);
		}
	}
}

static void	ft_success(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		return ;
	else if (sig == SIGUSR2)
		ft_printf("\033[32m[SUCESS]\033[0m: signal sent to \033[0;33m[%d]\033[0m\n",
			info->si_pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sa_usr;

	sa_usr.sa_flags = SA_SIGINFO;
	sa_usr.sa_sigaction = ft_success;
	if (ft_atoi(av[1]) >= 4294967295)
		ft_error();
	else if (ac == 3 && ft_check(av[1]) == 0)
	{
		sigaction(SIGUSR1, &sa_usr, NULL);
		sigaction(SIGUSR2, &sa_usr, NULL);
		ft_send(ft_atoi(av[1]), av[2]);
	}
	else
	{
		ft_printf("Usage: ./client <PID> <MESSAGE>\n");
		exit(0);
	}
	return (0);
}
