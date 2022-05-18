/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:57 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/18 21:02:02 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only
#include <stdio.h>*/

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
    char        str[18] = "lord of the misery";
    char        *out;

    f.dot = 1;
    f.precision = 10;
    out = print_s(str, &f);
    printf("%s\n",out);
    return (0);
}*/