/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:04:34 by user              #+#    #+#             */
/*   Updated: 2022/05/06 23:22:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_uitoa_base(const char *str, unsigned int n);

char    *print_p(unsigned long int ptr)
{
    char    *out;
    char    *buf;
    int         len;
    int         blen;

    buf = ft_uitoa_base(HEXLO, ptr);
    if (!buf)
        return (NULL);
    blen = strlen(buf);
    len = blen + 2;
    out = xput(buf, len, (blen - 1));
    if (!out)
        return (NULL);
    free (buf);
    out[1] = 'x';
    return (out);
}

/*for test only*/
int main()
{
    char    *ptr;

    ptr = print_p(2938041039);
    printf("%s\n", ptr);
    return (0);
}