/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:47:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/28 04:20:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char *dospace(char *str);
static char *doplus(char *str);
static char *dohash(char *str, char c);

char    *ft_doflag(char *str, t_param *f)
{
    if (f->plus && (f->type == 'i' || f->type == 'd'))
        str = doplus(str);
    if ((f->type == 'x' || f->type == 'X') && f->hash)
        str = dohash(str, f->type);
    else
        str = dospace(str);
    f->len = ft_strlen(str);
    return (str);
}

static char *dospace(char *str)
{
    char    *space;

    if (str[0] == '-' || str[0] == '+')
        return (str);
    space = ft_calloc(1, ft_strlen(str) + 2);
    if (!space)
        return (NULL);
    space[0] = ' ';
    space = ft_strcat(space, str);
    free(str);
    return (space);
}

static char *doplus(char *str)
{
    char   *plus;

    if (str[0] == '-' || str[0] == '+')
        return (str);
    plus = ft_calloc(1, ft_strlen(str) + 2);
    if (!plus)
        return (NULL);
    plus[0] = '+';
    plus = ft_strcat(plus, str);
    free(str);
    return (plus);
}

static char *dohash(char *str, char c)
{
    char    *hash;

    hash = ft_calloc(1, ft_strlen(str) + 3);
    if (!hash)
        return (NULL);
    hash[0] = '0';
    hash[1] = c;
    hash = ft_strcat(hash, str);
    free(str);
    return (hash);
}