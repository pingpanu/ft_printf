/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:04:40 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/24 23:36:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>*/

static char *xlocap(char c, unsigned int unb);

int    *print_x(unsigned int unb, t_param f)
{
    char    *out;

    if (f.dot && !f.precision && unb == 0)
        return (0);
    out = xlocap(f.type, unb);
    if (!out)
        return (NULL);
    f.len = ft_strlen(out);
    if (f.dot && f.precision > f.len)
        out = idux_prec(out, &f);
    if (f.hash)
        out = ft_doflag(out, &f);
    if (f.width > f.len)
        out = ft_dowidth(out, &f);
    f.len = printstr(out);
    free(out)
    return (f.len);
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