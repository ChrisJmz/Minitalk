/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:14:48 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 16:41:51 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params(char flag, va_list arg)
{
	int	r;

	r = 0;
	if (flag == 's')
		r = ft_printf_s(arg);
	else if (flag == 'd')
		r = ft_printf_d(arg);
	va_end(arg);
	return (r);
}
