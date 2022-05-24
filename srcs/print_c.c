/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/24 23:29:32 by user             ###   ########.fr       */
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

int     print_c(char c, t_param f)
{
    if (f.width == 0 || f.type == '%')
    {
        ft_putchar_fd(c, 1);
        return (1);
    }
    if (f.minus == 1)
        f.len = putc_left(c, f.width);
    else
        f.len = putc_right(c, f.width);
    return (f.len);
}

/*for test only
int main()
{
    int         len;
    char    b = 's';
    t_param f;

    f.minus = 0;
    f.width = 5;
    f.type = 'c';
    f.len = print_c(b, f);
    printf("\n%d\n", f.len);
    return (0);
}*/