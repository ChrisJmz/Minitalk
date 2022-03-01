/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:20:59 by cjimenez          #+#    #+#             */
/*   Updated: 2022/03/01 16:48:32 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_params(char flag, va_list arg);
int		ft_printf_s(va_list arg);
int		ft_printf_d(va_list arg);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);

#endif
