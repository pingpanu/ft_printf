/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:31:00 by user              #+#    #+#             */
/*   Updated: 2022/05/28 04:20:56 by user             ###   ########.fr       */
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

    if (nbr == 0)
        return (1);
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

    base = ft_strlen(str);
    ilen = ft_intlen(base, n);
    num = (char*)malloc(ilen + 1);
    if (!num)
        return (NULL);
    num[ilen--] = '\0';
    while (n > 0)
    {
         num[ilen--] = str[n % base];
         n /= base;
    }
    if (ilen == 0 && num[1] == '\0')
        num[0] = '0';
    return (num);
}
/*
int main()
{
    char    hex[16] = "0123456789abcdef";
    char    *out;

    out = ft_uitoa_base(hex, 0);
    printf("%s\n", out);
    return (0);
}*/