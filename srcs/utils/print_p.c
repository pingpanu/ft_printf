/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:04:34 by user              #+#    #+#             */
/*   Updated: 2022/05/12 21:04:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

static unsigned int    ulilen(size_t base, unsigned long int nbr)
{
    unsigned int  len;

    len = 0;
    while (nbr != 0)
    {
        nbr = nbr / base;
        len++;
    }
    return (len);
}

const char    *ft_ulitoa(unsigned long int ptr)
{
    unsigned int    ilen;
    size_t          base;
    char    *num;

    if(ptr == 0)
    {
        num = ft_calloc(1, 2);
        num[0] = '0';
        return (num);
    }
    ilen = ft_ulilen(16, ptr);
    num = ft_calloc(1, ilen + 1);
    if (!num)
        return (NULL);
    ilen -= 1;
    while (ptr > 0)
    {
        num[ilen--] = HEXLO[ptr % 16];
        ptr /= 16;
    }
    return (num);
}

char    *print_p(unsigned long int ptr)
{
    char    *out;
    char    *buf;
    int         len;
    int         blen;

    buf = ft_ulitoa(ptr);
    if (!buf)
        return (NULL);
    blen = ft_strlen(buf);
    len = blen + 2;
    out = xput(buf, len, (blen - 1));
    if (!out)
        return (NULL);
    free (buf);
    out[1] = 'x';
    return (out);
}

/*for test only
int main()
{
    char    *ptr;

    ptr = print_p(2938041039);
    printf("%s\n", ptr);
    return (0);
}*/