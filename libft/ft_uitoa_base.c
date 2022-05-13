/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:31:00 by user              #+#    #+#             */
/*   Updated: 2022/05/12 21:35:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*for test only
#include <string.h>
#include <stdlib.h>
#include <stdio.h>*/

static size_t     ft_intlen(size_t base, unsigned int nbr)
{
    size_t  len;

    len = 0;
    while (nbr != 0)
    {
        nbr = nbr / base;
        len++;
    }
    return (len);
}

char    *ft_uitoa_base(const char *str, unsigned int n)
{
    size_t      ilen;
    size_t      base;
    char    *num;

    if(n == 0)
    {
        num = ft_calloc(1, 2);
        num[0] = '0';
        return (num);
    }
    base = ft_strlen(str);
    ilen = ft_intlen(base, n);
    num = ft_calloc(1, ilen + 1);
    if (!num)
        return (NULL);
    ilen -= 1;
    while (n > 0)
    {
         num[ilen--] = str[n % base];
         n /= base;
    }
    return (num);
}