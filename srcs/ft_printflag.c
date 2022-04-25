/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:32:01 by user              #+#    #+#             */
/*   Updated: 2022/04/25 16:00:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char *plusspace(char str, t_param *f)
{
    char    *tmps;
        
    tmps = ft_calloc(1, 2);
    if (!tmps)
        return (NULL);
    if (f->plus == 1)
        tmps[0] = '+';
    if (f->space == 1)
        tmps[0] = ' ';
    str = ft_strcat(tmps, str);
    free (tmps);
    return (str);
}

static char *hash(char str, t_param *f)
{
    char    *tmps;

    tmps = ft_calloc(1,3);
    if (!tmps)
        return (NULL);
    tmps[0] = '0';
    tmps[1] = f->type;
    str = ft_strcat(tmps, str);
    free(tmps);
    return (str);
}

char    *ft_printflag(char *buf, t_param *f)
{
    int check;

    if (f->type == 'd' || f->type == 'i')
    {
        check = ft_atoi(buf);
        if (buf >= 0)
            buf = plusspace(buf, f);
    }
    if ((f->type = 'x' || f->type == 'X') && f->hash == 1)
        buf = hash(buf, f);
    if (!buf)
        return (NULL);
    return (buf);
}