/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/11 23:11:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	printstr(const char *str);

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
	out = ft_dowidth(out, f);
	len = printstr(out);
	free(out);
    return (len);
}

static int	printstr(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		write(1, *str, 1);
		str++;
		len++;
	}
	return (len);
}