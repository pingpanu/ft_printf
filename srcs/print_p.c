/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:34 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/27 21:18:54 by pingpanu         ###   ########.fr       */
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

int    print_p(unsigned long int ptr, t_param f)
{
    char    *out;
    int         blen;

    out = ft_ulitoa(ptr);
    if (!out)
        return (0);
    blen = ft_strlen(out);
    f.len = blen + 2;
    out = xput(out, f.len, (blen - 1));
    if (!out)
        return (0);
    out[1] = 'x';
    f.len = printstr(out);
    free(out);
    return (f.len);
}

/*for test only
int main()
{
    int     a = 10;
    int     *b;
    t_param f;

    b = &a;
    f.len = print_p((unsigned long int)b, f);
    printf("\n%d\n", f.len);
    return (0);
}*/