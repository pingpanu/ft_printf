/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:45:30 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/18 21:40:26 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	printstr(const char *str);

int ft_putall(t_param *f, va_list ap)
{
    char    *out;
    int         len;
	
	if (f->type == 'c')
		len = print_c(va_arg(ap, int), f);
	if (f->type == '%')
		len = print_c('%', f);
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
		ft_putchar_fd(*str++, 1);
		len++;
	}
	return (len);
}