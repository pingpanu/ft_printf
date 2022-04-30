/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:23:50 by user              #+#    #+#             */
/*   Updated: 2022/04/30 23:02:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char flag_id(t_param *f, int n);

char    *print_id(int nbr, t_param *f)
{
    char    *out;
    char    *buf;
    int         len;
    int         blen;

    if (f->dot && f->precision == 0 && nbr == 0)
        return (NULL);
    buf = ft_uitoa_base(DIGIT, (unsigned int *)nbr);
    len = ft_strlen(buf);
    blen = len;
    if (f->precision > blen)
        len = f->precision;
    if (f->plus || f->space || nbr < 0)
        len += 1;
    out = (char *)ft_calloc(1, (len + 1));
    if (!out)
        return(NULL);
    while (len >= 0)
    {
        if (blen >= 0)
            out[len--] = buf[blen--];
        out[len--] = '0'; 
    }
    out[0] = getflag(f, nbr);
    free(buf);
    return (out);
}

static char flag_id(t_param *f, int n)
{
    char    flag;

    if ((n >= 0 && (f->plus || f->space)) || n < 0)
    {
        if (f->plus)
            flag = '+';
        if (f->space)
            flag = ' ';
        if (n < 0)
            flag = '-';
        return (flag);
    }
    else
        flag = '0';
    return (flag);
}