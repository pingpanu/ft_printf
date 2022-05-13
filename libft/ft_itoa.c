/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:31:00 by user              #+#    #+#             */
/*   Updated: 2022/05/10 21:44:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*for test only
#include <string.h>
#include <stdlib.h>
#include <stdio.h>*/

static size_t     ft_intlen(size_t base, int n)
{
    size_t  len;
    unsigned int    ui;

    len = 0;
    ui = n;
    if (n < 0)
    {
        len = 1;
        ui = n * -1;
    }
    while (ui != 0)
    {
        ui = ui / base;
        len++;
    }
    return (len);
}

static char *putnum(unsigned int nbr, size_t ilen)
{
    char    *out;

    out = ft_calloc(1, (ilen + 1));
    if (!out)
        return (NULL);
    ilen -= 1;
    while (nbr > 0)
    {
        out[ilen--] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return (out);
}

char    *ft_itoa(int n)
{
    size_t      ilen;
    unsigned int nbr;
    char    *num;

    if(n == 0)
    {
        num = ft_calloc(1, 2);
        num[0] = '0';
        return (num);
    }
    ilen = ft_intlen(10, n);
    nbr = n;
    if (n < 0)
        nbr = n * -1;
    num = putnum(nbr, ilen);
    if (num)
    {
        if (n < 0)
            num[0] = '-';
        return (num);
    }
    return (NULL);
}

/*for test only
int main()
{
    char    *buf1;
    char    *buf2;
    char    *buf3;

    buf1 = ft_itoa(-42);
    buf2 = ft_itoa(0);
    buf3 = ft_itoa(42);
    printf("%s\n",buf1);
    printf("%s\n",buf2);
    printf("%s\n",buf3);
    return (0);
}*/