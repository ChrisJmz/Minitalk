/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:33:37 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/07 14:11:34 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int  ft_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

static int  ft_error(void)
{
    ft_printf("Unable to send signal\n");
    exit(0);
}

static void ft_send(int pid, char *msg)
{
    int i;
    int j;
    int size;

    i = 0;
    size = ft_strlen(msg);
    while (i <= size)
    {
        j = 7;
        while (j > -1)
        {
            if (msg[i] >> j & 1)
            {
                if (kill(pid, SIGUSR1))
                    ft_error();
            }
            else
            {
                if (kill(pid, SIGUSR2))
                    ft_error();
            }
            usleep(500);
            j--;
        }
        i++;
    }
}

static void ft_success(int sig)
{
    if (sig == SIGUSR1)
        return;
    else if (sig == SIGUSR2)
        ft_printf("\033[32m>>>>>Signal received!<<<<<\033[0m\n");
}

int main(int ac, char **av)
{
    if (ac == 3 && ft_check(av[1]) == 0)
    {
        signal(SIGUSR1, ft_success);
        signal(SIGUSR2, ft_success);
        ft_send(ft_atoi(av[1]), av[2]);

    }
    else
    {
        ft_printf("Usage: ./client <PID> <MESSAGE>\n");
        exit(0);
    }
    return (0);
}