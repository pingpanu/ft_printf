/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:32:01 by user              #+#    #+#             */
/*   Updated: 2022/04/16 20:50:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char *ft_addf(char c, char *str)
{
    char    *tmps; //temporary string

    if (c == ' ' || c == '+')
    {
        tmps = ft_calloc(1, 2);
        tmps[0] = c;
    }
    if (c == '#')
    {
        tmps = ft_calloc(1,3);
        tmps[0] = '0';
        tmps[1] = 'x';
    }
    str = ft_strjoin(tmps, str);
    free(tmps);
    return (str);
}

char    *ft_printflag(char *buf, t_param f)
{
    if (f.type == 'd' || f.type == 'i')
    {
        if (f.space == 1)
            return (ft_addf(' ', buf));
        if (f.plus == 1)
            return (ft_addf('+', buf));
    }
    if ((f.type = 'x' || f.type == 'X') && f.hash == 1)
        return (ft_addf('#', buf));
}