/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:02:18 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/30 15:19:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char     *ft_putspecs(t_param *f, va_list ap)
{
    char    *print;

    if (f->type == 'i' || f->type == 'd')
        print = print_id(va_arg(ap, int), f);
    if (f->type == 's')
        print = print_s(va_arg(ap, char *), f);
    if (f->type == 'p')
        print = print_p(va_arg(ap, unsigned long int));
    if (f->type == 'u')
        print = print_u(va_arg(ap, int), f);
    if (f->type == 'x')
        print = print_x(va_arg(ap, unsigned int), f);
    if (f->type == 'X')
        print = print_x(va_arg(ap, unsigned int), f);
    else
        print = ft_calloc(sizeof(char), 1);
    if (!print)
        return (NULL);
    return (print);
}