/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:45:05 by user              #+#    #+#             */
/*   Updated: 2022/05/06 23:26:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *idput(char *buf, int len, int blen)
{
    char    *out;

    out = calloc(1, (len + 1));
    if (!out)
        return (NULL);
    len -= 1;
    while (blen >= 0 && ft_isdigit(buf[blen]))
            out[len--] = buf[blen--];
    while (len >= 0)
        out[len--] = '0';
    return (out);
}

char putflag(t_param *f, int n)
{
    if (f->type == 'i' || f->type == 'd')
    {
        if (n >= 0 && (f->plus || f->space))
        {
            if (f->plus)
                return ('+');
            if (f->space)
                return (' ');
        }
        if (n < 0)
            return ('-');
    }
    if (f->type == 'x' || f->type == 'X')
    {
        if (f->hash)
            return (f->type);
    }
    return ('0');
}

char *xput(char *buf, int len, int blen)
{
    char    *out;

    out = calloc(1, (len + 1));
    if (!out)
        return (NULL);
    len -= 1;
    while (blen >= 0)
            out[len--] = buf[blen--];
    while (len >= 0)
        out[len--] = '0';
    return (out);
}