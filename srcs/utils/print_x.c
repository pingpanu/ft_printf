/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:47:45 by user              #+#    #+#             */
/*   Updated: 2022/04/30 23:10:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char *putbuf_x(char c, unsigned int unb);

char    *print_x(unsigned int unb, t_param *f)
{
    char    *out;
    char    *buf;
    int         blen;
    int         len;

    if (f->dot && !f->precision && unb == 0)
        return (NULL);
    buf = putbuf_x(f->type, unb);
    len = ft_strlen(buf);
    blen = len;
    if (f->precision > blen)
        len = f->precision;
    if (f->hash)
        len += 2;
    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    while (len >= 0)
    {
        if (blen >= 0)
            out[len--] = buf[blen--];
        out[len--] = '0';
        if (f->hash && len == 1)
            out[len--] = f->type;
    }
    return (out);
}

static char *putbuf_x(char c, unsigned int unb)
{
    char    *res;

    if (c = 'X')
        res = ft_itoa_base(HEXCAP, unb);
    else
        res = ft_uitoa_base(HEXLO, unb);
}