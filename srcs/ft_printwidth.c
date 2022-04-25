/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:22:28 by user              #+#    #+#             */
/*   Updated: 2022/04/25 16:00:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char *doprecision(char *str, int prc);

char    *ft_printwidth(char *str, t_param *f)
{
    char    *dstr;

    if (f->precision == 0 && f->dot == 1)
    {
        if (f->type == 'c' || f->type == 's')
            return(ft_putnull);
        else
        {
            dstr = ft_calloc(2, 1);
            dstr[0] = ' ';
        }
    }
    if (f->precision > 0)
        dstr = doprecision(str, f->precision);
    if (f->width > f->precision)
        dstr = ft_dowidth(dstr, &f);
    return (dstr);
}

static char *doprecision(char *str, int prc)
{
    char    *out;
    int     slen;
    int     i;

    i = 0;
    slen = ft_strlen(str);
    out = ft_calloc(1, (prc - slen + 1));
    while (i < prc - slen)
        out[i++] = '0';
    out = ft_strjoin(out, str);
    return (out);
}