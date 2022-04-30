/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:32 by user              #+#    #+#             */
/*   Updated: 2022/04/29 11:39:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int  putc_left(char c, int width)
{
    int     i;

    i = 0;
    while (i++ < width)
    {
        if (i == 0)
            ft_putchar_fd(c, 1);
        ft_putchar_fd(' ', 1);
    }
    return (i);
}

static int  putc_right(char c, int width)
{
    int     i;

    i = 0;
    while (i++ < width)
    {
        if (i == width - 1)
            ft_putchar_fd(c, 1);
        ft_putchar_fd(' ', 1);
    }
    return (i);
}

int     print_c(char c, t_param *f)
{
    int    i;

    if (f->width == 0 || c == '%')
    {
        ft_putchar_fd(c, 1);
        return (1);
    }
    if (f->minus == 1)
        i = putc_left(c, f->width);
    i = putc_right(c, f->width);
    return (i);
}