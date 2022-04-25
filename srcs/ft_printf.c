/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/21 00:37:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_putall(t_param *f, va_list ap);

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
			done += ft_putall(&f, arg);
		}
	}
	va_end (arg);
	return (done);
}

static int ft_putall(t_param *f, va_list ap)
{
    char    *out;
    int     len;

    out = ft_putspecs(f, ap);
	len = ft_strlen(out);
	ft_putstr_fd(out, 1);
	free(out);
    return (len);
}