/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:02:18 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/25 15:47:12 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static  ft_print_cases_f const ft_print_cases[256] = {
    ['c'] = printf_char,
    ['d'] = printf_num,
    ['i'] = printf_num,
    ['o'] = printf_oc,
    ['u'] = printf_dec,
    ['x'] = printf_hex,
    ['X'] = printf_hexup,
    ['s'] = printf_string,
};

static int     ft_print_aux(const char *fmt, va_list ap, int len)
{
    int     c;

    while (*fmt)
    {
        c = (unsigned char)*fmt++;
        if (c != '%')
        {
            ft_putchar_fd(c, 1);
            len++;
        }
        else
        {
            c = (unsigned char)*fmt++;
            if (ft_print_cases[c] == NULL)
            {
                if (c == '\0')
                    break ;
                ft_putchar_fd(c, 1);
                len++;
            }
            else
                return (ft_print_cases[c](fmt, ap, len));
        }
    }
    return (len);
}

int     ft_vprintf(const char *fmt, va_list ap)
{
    return (ft_print_aux(fmt, ap, 0));
}