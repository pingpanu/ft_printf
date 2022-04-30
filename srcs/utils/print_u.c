/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:38:07 by user              #+#    #+#             */
/*   Updated: 2022/04/30 23:02:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *print_u(unsigned int nb, t_param *f)
{
    char    *buf;
    char    *out;
    int             len;
    int             blen;

    if (f->dot && f->precision == 0 && nb == 0)
        return (NULL);
    buf = ft_uitoa_base(DIGIT, (unsigned int *)nb);
    len = ft_strlen(buf);
    blen = len;
    if (f->precision > blen)
        len = f->precision;
    out = ft_calloc(1, (len + 1));
    if (!out)
        return (0);
    while (len >= 0)
    {
        if (blen >= 0)
            out[len--] = buf[blen--];
        out[len--] = '0';
    }
    return (out);
}

