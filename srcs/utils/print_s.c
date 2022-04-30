/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:06:27 by user              #+#    #+#             */
/*   Updated: 2022/04/30 13:57:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char *nostr_handle(int prc);

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
    if (f->precision < len)
        len = f->precision;
    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    ft_memcpy(out, str, len);
    return (out);
}

static char *nostr_handle(int prc)
{
    char buf;

    if (IS_LINUX && prc < 6)
    {
        buf = ft_calloc(1, 1);
        return (buf);
    }
    buf = ft_calloc(1, (S_EMPTY_L + 1));
    ft_memcpy(buf, S_EMPTY, S_EMPTY_L);
    return (buf);
}