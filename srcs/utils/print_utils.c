/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:45:05 by user              #+#    #+#             */
/*   Updated: 2022/04/28 23:41:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int  ft_intlen(size_t base, int n)
{
    size_t  len;
    size_t  ui;

    len = 0;
    if (n < 0)
    {
        ui = -n;
        len += 1;
    }
    else
        ui = n;
    while (ui != 0)
    {
        n = n / base;
        len++;
    }
    return (len);
}

void puthex(char *c, t_param *f, int n)
{
    size_t  ui;
    int     i;

    if (f->plus && n >= 0)
        c[0] = '+';
    if (f->space && n >= 0)
        c[0] = ' ';
    if (n < 0)
    {
        c[0] = '-';
        ui = n * -1;
    }
    else
        ui = n;
    i = 0;
    if (c[i] == '+' || c[i] == '-' || c[i] == ' ')
        i = 1;
    while (c[i++])
    {
        if (i < f->precision)
            c[i] = '0';
        else
            c[i] = DIGIT[ui % 10];
    }
    return (c);
}