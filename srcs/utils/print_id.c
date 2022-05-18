/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:16 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/13 15:06:21 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

char    *ft_itoa(int n);

char    *print_id(int nbr, t_param *f)
{
    char    *out;
    char    *buf;
    int         len;
    int         blen;

    if (f->dot == 1 && f->precision == 0 && nbr == 0)
        return ("");
    buf = ft_itoa(nbr);
    if (!buf)
        return (NULL);
    blen = ft_strlen(buf);
    if (f->precision <= blen && !f->space && !f->plus)
        return (buf);
    len = blen;
    if (f->precision > blen)
        len = f->precision;
    if (f->plus || f->space || nbr < 0)
        len += 1;
    out = idput(buf, len, (blen - 1));
    free(buf);
    if (out)
    {
        out[0] = putflag(f, nbr);
        return (out);
    }
    return(NULL);
}

/*for test only
int main()
{
    t_param f;
    char    *out;

    f.type = 'd';
    f.dot = 1;
    f.plus = 1;
    f.space = 0;
    f.precision = 0;
    out = print_id(0, &f);
    printf("%s\n",out);
    return (0);
}*/