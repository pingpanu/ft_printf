/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:32:51 by user              #+#    #+#             */
/*   Updated: 2022/04/25 16:00:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char addright(int wdiff, char *str);
static char addleft(int wdiff, char *str, t_param *f);

char    *ft_dowidth(char *str, t_param *f)
{
    int     wdiff;
    char    *out;

    wdiff = f->width - ft_strlen(str);
    if (wdiff <= 0)
        return (str);
    else
    {
        if (f->minus == 1)
            out = addright(wdiff, *str);
        else
            out = addleft(wdiff, *str, f);
        free(str);
        return (out);
    }
}

static char addright(int wdiff, char *str)
{
    char    *rstr;
    int     i;

    i = 0;
    rstr = ft_calloc(1,wdiff + 1);
    while (i <= wdiff)
        rstr[i++] = ' ';
    str = ft_strjoin(str, rstr);
    free (rstr);
    return (str);   
}

static char addleft(int wdiff, char *str, t_param *f)
{
    char    *rstr;
    int     i;

    i = 0;
    rstr = ft_calloc(1,wdiff + 1);
    while (i <= wdiff)
        rstr[i++] = f->lead;
    str = ft_strjoin(rstr, str);
    free (rstr);
    return (str);   
}