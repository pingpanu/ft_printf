/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:02:18 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/04 23:20:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_putspecs(t_param *f, va_list ap)
{
    char    *print;
    int         len;

    len = 0;
    if (f->type == 'i' || f->type == 'd')
        print = print_num(va_arg(ap, int));
    if (f->type == 'c')
        print = print_c(va_arg(ap, char));
    if (f->type == 's')
        print = print_s(va_arg(ap, char *));
    if (f->type == 'p')
        print = print_p(va_arg(ap, unsigned long int));
    if (f->type == 'u')
        print = print_u(va_arg(ap, int));
    if (f->type == 'x')
        print = print_x(va_arg(ap, int), 0);
    if (f->type == 'X')
        print = print_x(va_arg(ap, int), 1);
    if (f->type == '%')
        print = print_c('%');
    else
        print = ft_calloc(sizeof(char), 1);
    len = ft_strlen(print);
    ft_putstr_fd(print,1);
    free (print);
    return (len);
}