/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:17:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/25 15:47:01 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     printf_char(const char *fmt, va_list ap, int len)
{
    int c;
    c = va_arg(ap, int);
    ft_putchar_fd(c, 1);
    return (ft_print_aux(fmt, ap, len + 1));
}

static int  ft_putnbr_base(size_t   n, unsigned int base, const char *digits)
{
    int res;
    if (n >= base)
        res += ft_putnbr_base(n / base, base, digits);
    ft_putchar_fd(digits[n % base], 1);
    return (res);
}

int     printf_num(const char *fmt, va_list ap, int len)
{
    int     n;
    size_t  u;

    n = va_arg(ap, int);
    if (n < 0)
    {
        ft_putchar_fd('-', 1);
        len++;
        u = -(unsigned)n;
    }
    else
        u = n;
    len += ft_putnbr_base(u, 10, "0123456789");
    return (ft_print_aux(fmt, ap, len));
}

int     printf_oc(const char *fmt, va_list ap, int len)
{
    unsigned int    n;

    n = va_arg(ap, unsigned int);
    len += ft_putnbr_base(n, 8, "01234567");
    return(ft_print_aux(fmt, ap, len));
}

int     printf_hex(const char *fmt, va_list ap, int len)
{
    unsigned int       n;

    n = va_arg(ap, unsigned int);
    len += ft_putnbr_base(n, 16, "0123456789abcdef");
    return (ft_print_aux(fmt, ap, len));
}

int     printf_hexup(const char *fmt, va_list ap, int len)
{
    unsigned int       n;

    n = va_arg(ap, unsigned int);
    len += ft_putnbr_base(n, 16, "0123456789ABCDEF");
    return (ft_print_aux(fmt, ap, len));
}

int     printf_string(const char *fmt, va_list ap, int len)
{
    const char  *s;

    s = va_arg(ap, const char *);
    if (s == NULL)
        s = "(null)";
    len += ft_strlen(s);
    ft_putstr_fd(s, 1);
    free(s);
    return (ft_print_aux(fmt, ap, len));
}