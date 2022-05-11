/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:32:51 by user              #+#    #+#             */
/*   Updated: 2022/05/11 23:09:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*for test only
#include <string.h>
#include <stdio.h>
#include <stdlib.h>*/

static char *align_left(int width, char *str);
static char *align_right(int width, char *str, t_param *f);

char    *ft_dowidth(char *str, t_param *f)
{
    char    *out;

    if (!str)
    {
        out = nostr_handle(f->precision);
        return (out);
    }
    if (f->width > (int)ft_strlen(str))
    {
        if (f->minus == 1)
            out = align_left(f->width, str);
        else
            out = align_right(f->width, str, f);
        if(!out)
            return (NULL);
        free(str);
        return (out);
    }
    return (str);
}

static char *align_left(int width, char *str)
{
    char    *rstr;
    int         i;

    i = 0;
    rstr = ft_calloc(1, width + 1);
    if (!rstr)
        return (NULL);
    while (*str)
        rstr[i++] = *str++;
    while (rstr[i])
        rstr[i++] = ' ';
    return (rstr);
}

static char *align_right(int width, char *str, t_param *f)
{
    char    *rstr;
    int     slen;

    slen = ft_strlen(str);
    rstr = ft_calloc(1, width + 1);
    if (!rstr)
        return (NULL);
    while (slen >= 0)
        rstr[width--] = str[slen--];
    while (width >= 0)
        rstr[width--] = f->lead;
    return (rstr);
}

/*for test only
int main()
{
    t_param f;
    char    *out;

    f.width = 10;
    f.minus = 0;
    f.lead = ' ';
    out = ft_dowidth("0042", &f);
    printf("%s\n", out);
    return (0);
}*/