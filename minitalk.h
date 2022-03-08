/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:07:31 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/07 13:57:35 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "ft_printf/ft_printf.h"
# include <signal.h>
#include <stdlib.h>
#include <sys/signal.h>
# define buffer 100000

int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif
