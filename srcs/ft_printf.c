/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:05:02 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/27 23:06:22 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;
	int			i;
	t_param		f;

	i = 0;
	done = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			f = get_params(format, f, &i);
			done += ft_putall(f, arg);
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			f.len++;
		}
	}
	va_end (arg);
	return (done);
}