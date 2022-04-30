/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/30 15:10:36 by user             ###   ########.fr       */
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
	
	if (f->type == 'c')
	{
		len = print_c(va_arg(ap, int), f);
		return (len);
	}
	if (f->type == '%')
	{
		len = print_c('%', f);
		return (len);
	}
    out = ft_putspecs(f, ap);
	out = ft_dowidth(out, f); //do both width and precision
	len = printstr(out);
	free(out);
    return (len);
}