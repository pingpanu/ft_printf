/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:32:51 by user              #+#    #+#             */
/*   Updated: 2022/05/12 20:44:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

/*for test only
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>*/

static char *align_left(int width, char *str);
static char *align_right(int width, char *str, t_param *f);
static void id_withzero(char *rstr, char *str);

char    *ft_dowidth(char *str, t_param *f)
{
    char    *out;

    if (!str)
    {
        out = nostr_handle(f->precision);
        return (out);
    }
    if ((f->width > (int)ft_strlen(str)) && f->type != 'p')
    {
        if (f->minus == 1)
            out = align_left(f->width, str);
        else
            out = align_right(f->width, str, f);
        if(!out)
            return (NULL);
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
    if ((f->type == 'i' || f->type == 'd') && f->lead == '0')
        id_withzero(rstr, str);
    return (rstr);
}

static void id_withzero(char *rstr, char *str)
{
    int     ptr;

    ptr = 1;
    if (str[0] == '-')
        rstr[0] = '-';
    while (rstr[ptr])
    {
        if (rstr[ptr] == '-')
            rstr[ptr] = '0';
        ptr++;
    }
}

/*for test only
int main()
{
    t_param f;
    char    *out;

    f.width = 10;
    f.minus = 0;
    f.lead = '0';
    f.type = 'x';
    out = ft_dowidth("123", &f);
    printf("%s\n", out);
    return (0);
}*/