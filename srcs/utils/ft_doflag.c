/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:47:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/28 15:34:34 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char *dospace(char *str, int len);
static char *doplus(char *str, int len);
static char *dohash(char *str, t_param *f);

char    *ft_doflag(char *str, t_param *f)
{
    if (f->plus && (f->type == 'i' || f->type == 'd'))
        str = doplus(str, f->len);
    if ((f->type == 'x' || f->type == 'X') && f->hash)
        str = dohash(str, f);
    else
        str = dospace(str, f->len);
    f->len = ft_strlen(str);
    return (str);
}

static char *dospace(char *str, int len)
{
    char    *space;

    if (str[0] == '-' || str[0] == '+')
        return (str);
    space = ft_calloc(1, len + 2);
    if (!space)
        return (NULL);
    space[0] = ' ';
    space = ft_strcat(space, str);
    free(str);
    return (space);
}

static char *doplus(char *str, int len)
{
    char   *plus;

    if (str[0] == '-' || str[0] == '+')
        return (str);
    plus = ft_calloc(1, len + 2);
    if (!plus)
        return (NULL);
    plus[0] = '+';
    plus = ft_strcat(plus, str);
    free(str);
    return (plus);
}

static char *dohash(char *str, t_param *f)
{
    char    *hash;

    hash = ft_calloc(1, f->len + 3);
    if (!hash)
        return (NULL);
    hash[0] = '0';
    hash[1] = f->type;
    hash = ft_strcat(hash, str);
    free(str);
    return (hash);
}