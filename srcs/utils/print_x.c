/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:04:40 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/13 15:05:21 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

static char *xlocap(char c, unsigned int unb);

char    *print_x(unsigned int unb, t_param *f)
{
    char    *out;
    char    *buf;
    int         blen;
    int         len;

    if (f->dot && !f->precision && unb == 0)
        return ("");
    buf = xlocap(f->type, unb);
    if (!buf)
        return (NULL);
    blen = ft_strlen(buf);
    if (f->precision <= blen && !f->hash)
        return (buf);
    len = blen;
    if (f->precision > blen)
        len = f->precision;
    if (f->hash)
        len += 2;
    out = xput(buf, len, (blen - 1));
    free (buf);
    if (out)
    {
        out[1] = putflag(f, unb);
        return (out);
    }
    return (NULL);
}

static char *xlocap(char c, unsigned int unb)
{
    char    *buf;

    if (c == 'X')
        buf = ft_uitoa_base(HEXCAP, unb);
    else
        buf = ft_uitoa_base(HEXLO, unb);
    if (!buf)
        return (NULL);
    return (buf);
}

/*for test only
int main()
{
    t_param f;
    char    *out;

    f.type = 'x';
    f.dot = 0;
    f.hash = 0;
    f.precision = 0;
    out = print_x(-123, &f);
    printf("%s\n",out);
    return (0);
}*/