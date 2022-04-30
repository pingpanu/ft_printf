/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:04:34 by user              #+#    #+#             */
/*   Updated: 2022/04/30 23:10:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *print_p(unsigned long int ptr)
{
    char    *out;
    char    *buf;
    int         len;
    int         blen;

    buf = ft_uitoa_base(HEXCAP, ptr);
    blen = ft_strlen(buf);
    len = blen +2;
    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    while (blen >= 0)
        out[len--] = buf[blen--];
    out[1] = 'x';
    out[0] = '0';
    return (out);
}