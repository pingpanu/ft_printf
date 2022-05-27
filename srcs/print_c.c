/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/27 23:11:10 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*for test only
#include <stdio.h>*/

static int  putc_left(char c, t_param *f)
{
    while (f->len < f->width)
    {
        if (f->len == 0)
            ft_putchar_fd(c, 1);
        ft_putchar_fd(' ', 1);
        f->len++;
    }
    return (f->width);
}

static int  putc_right(char c, t_param *f)
{
    while (f->len < f->width)
    {
        if (f->len == f->width - 1)
            ft_putchar_fd(c, 1);
        ft_putchar_fd(' ', 1);
        f->len++;
    }
    return (f->width);
}

int     print_c(char c, t_param f)
{
    int     len;

    if (f.minus == 1 && f.width > 1)
        len = putc_left(c, &f);
    else if (f.minus == 0 && f.width > 1)
        len = putc_right(c, &f);
    else
        len = write(1, &c, 1);
    return (len);
}

/*for test only
int main()
{
    int         len;
    char        b = '0';
    t_param f;

    f.minus = 0;
    f.width = 3;
    f.type = 'c';
    f.len = print_c(b, f);
    printf("\n%i\n", f.len);
    f.len = printf("%3c\n",'0');
    printf("%i\n", f.len);
    return (0);
}*/