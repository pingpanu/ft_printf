/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/13 15:06:08 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*for test only
#include <stdio.h>*/

static int  putc_left(char c, int width)
{
    int     i;

    i = 0;
    while (i < width)
    {
        if (i == 0)
        {
            ft_putchar_fd(c, 1);
            i++;
        }
        ft_putchar_fd(' ', 1);
        i++;
    }
    return (i);
}

static int  putc_right(char c, int width)
{
    int     i;

    i = 0;
    while (i < width)
    {
        if (i == width - 1)
            ft_putchar_fd(c, 1);
        ft_putchar_fd(' ', 1);
        i++;
    }
    return (i);
}

int     print_c(char c, t_param *f)
{
    int    i;

    if (f->width == 0 || f->type == '%')
    {
        ft_putchar_fd(c, 1);
        return (1);
    }
    if (f->minus == 1)
        i = putc_left(c, f->width);
    else
        i = putc_right(c, f->width);
    return (i);
}

/*for test only
int main()
{
    int         len;
    char    b = '%';
    t_param f;

    f.minus = 1;
    f.width = 5;
    f.type = 'c';
    len = print_c(b, &f);
    printf("\n%d\n", len);
    return (0);
}*/