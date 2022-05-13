/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:06:27 by user              #+#    #+#             */
/*   Updated: 2022/05/12 20:51:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

char    *print_s(char *str, t_param *f)
{
    char    *out;
    size_t  len;

    if (!str)
    {
        out = nostr_handle(f->precision);
        return (out);
    }
    if (f->dot && f->precision == 0)
    {
        out = ft_calloc(1, 1);
        return (out);
    }
    len = ft_strlen(str);
    if (f->precision < (int)len)
        len = f->precision;
    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    ft_memcpy(out, str, len);
    return (out);
}

/*for test only
int main()
{
    t_param f;
    char        str[14] = "Vous avez peri";
    char        *out;

    f.dot = 1;
    f.precision = 10;
    out = print_s('\0', &f);
    printf("%s\n",out);
    return (0);
}*/