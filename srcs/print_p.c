/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:34 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/28 03:30:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <limits.h>*/

static size_t    ullilen(size_t base, unsigned long long int nbr)
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

static char    *ft_ullitoa(unsigned long int ptr)
{
    size_t    ilen;
    char    *num;

    ilen = ullilen(16, ptr);
    num = (char*)malloc(ilen + 1);
    if (!num)
        return (NULL);
    num[ilen--] = '\0';
    while (ptr > 0)
    {
        num[ilen--] = HEXLO[ptr % 16];
        ptr /= 16;
    }
    if (ilen == 0 && num[1] == '\0')
        num[0] = '0';
    return (num);
}

static char     *p_hash(char *str, t_param *f)
{
    char    *phash;

    phash = ft_calloc(1, f->len + 3);
    if (!phash)
        return (NULL);
    phash[0] = '0';
    phash[1] = 'x';
    phash = ft_strcat(phash, str);
    free(str);
    f->len = ft_strlen(phash);
    return (phash);
}

int    print_p(unsigned long int ptr, t_param f)
{
    char    *out;

    if (ptr == 0)
    {
        out = ft_calloc(1, P_EMPTY_L + 1);
        ft_memcpy(out, P_EMPTY, P_EMPTY_L);
    }
    else
        out = ft_ullitoa(ptr);
    if (!out)
        return (0);
    f.len = ft_strlen(out);
    if (ptr != 0)
        out = p_hash(out, &f);
    if (f.width > f.len)
        out = ft_dowidth(out, &f);
    f.len = printstr(out);
    free(out);
    return (f.len);
}

/*for test only
int main()
{
    int     test = 42;
    t_param f;

    f.len = print_p(&test, f);
    printf("\n%d\n", f.len);
    return (0);
}*/