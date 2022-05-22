/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:34 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/22 22:36:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>*/

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

static char    *ft_ulitoa(unsigned long int ptr)
{
    unsigned int    ilen;
    char    *num;

    if(ptr == 0)
    {
        num = ft_calloc(1, 2);
        num[0] = '0';
        return (num);
    }
    ilen = ulilen(16, ptr);
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