/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/16 20:52:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;
	int			i; //pointer to format
	t_param		f; //format parameters after %

	done = -1;
	i = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], 1);
			done++;
		}
		else
		{
			i += 1;
			f = get_params(format, &f, &i);
			done += ft_putall(f, arg);
		}
	}
	va_end (arg);
	return (done);
}