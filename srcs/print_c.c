/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/27 22:45:48 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*for test only
#include <stdio.h>*/

static int  putc_left(char c, t_param *f)
{
    int     len;

    len = 0;
    while (f->len < f->width)
    {
        if (f->len == 0)
        {
            ft_putchar_fd(c, 1);
            len += 2;
            f->len++;
        }
        len += write(1, " ", 1);
        f->len++;
    }
    return (len);
}

static int  putc_right(char c, t_param *f)
{
    int     len;

    len = 0;
    while (f->len < f->width)
    {
        if (f->len == f->width - 1)
        {
            ft_putchar_fd(c, 1);
            len += 2;
        }
        len += write(1, " ", 1);
        f->len++;
    }
    return (len);
}

int     print_c(char c, t_param f)
{
    int     len;

    if (f.minus == 1 && f.width > 1)
        len = putc_left(c, &f);
    else if (f.minus == 0 && f.width > 1)
        len = putc_right(c, &f);
    else
    {
        len = 2;
        ft_putchar_fd(c, 1);
    }
    return (len);
}

/*for test only
int main()
{
    int         len;
    char        b = '0';
    t_param f;

    f.minus = 0;
    f.width = 0;
    f.type = 'c';
    f.len = print_c(b, f);
    printf("\n%i\n", f.len);
    f.len = printf("%c\n",'0');
    printf("%i\n", f.len);
    return (0);
}*/