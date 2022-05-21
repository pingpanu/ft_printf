/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:08:21 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/21 21:24:37 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>*/

char    *idput(char *buf, int len, int blen)
{
    char    *out;

    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    len -= 1;
    while (blen >= 0 && ft_isdigit(buf[blen]))
            out[len--] = buf[blen--];
    while (len >= 0)
        out[len--] = '0';
    return (out);
}

char *xput(char *buf, int len, int blen)
{
    char    *out;

    out = ft_calloc(1, (len + 1));
    if (!out)
        return (NULL);
    len -= 1;
    while (blen >= 0)
            out[len--] = buf[blen--];
    while (len >= 0)
        out[len--] = '0';
    return (out);
}

char *nostr_handle(int prc)
{
    char *buf;

    if (IS_LINUX && prc < 6)
    {
        buf = ft_calloc(1, 1);
        return (buf);
    }
    buf = ft_calloc(1, (S_EMPTY_L + 1));
    ft_memcpy(buf, S_EMPTY, S_EMPTY_L);
    return (buf);
}

int	printstr(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		ft_putchar_fd(*str++, 1);
		len++;
	}
	return (len);
}