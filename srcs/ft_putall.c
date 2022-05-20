/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:49:17 by user              #+#    #+#             */
/*   Updated: 2022/05/19 22:52:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_putall(t_param f, va_list ap)
{
    int		len;
	
	if (f.type == 'c')
		len = print_c(va_arg(ap, int), f);
	if (f.type == '%')
		len = print_c('%', f);
	if (f.type == 'i' || f.type == 'd')
        len = print_id(va_arg(ap, int), f);
    if (f.type == 's')
        len = print_s(va_arg(ap, char *), f);
    if (f.type == 'p')
        len = print_p(va_arg(ap, unsigned long int));
    if (f.type == 'u')
        len = print_u(va_arg(ap, int), f);
    if (f.type == 'x' || f.type == 'X')
        len = print_x(va_arg(ap, unsigned int), f);
    else
        return (0);
    return (len);
}