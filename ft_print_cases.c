/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:17:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/13 21:24:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char     *print_c(char c)
{
    char    *ret;

    ret = malloc(sizeof(char) * 2);
    ret[0] = c;
    ret[1] = '\0';
    return (ret);
}

char    *print_s(char *str)
{
    char    *out;
    size_t  len;

    len = ft_strlen(str);
    out = malloc(sizeof(char) * (len + 1));
    ft_memcpy(out, str, len + 1);
    return (out);
}

char    *print_id(int nbr)
{
    char    *out;

    out = ft_itoa_base(DIGIT, nbr);
    return (out);
}

char    *print_u(int nb)
{
    char    *out;
    unsigned int    uit;

    if (nb < 0 && nb > -4294967295)
        uit = 4294967295 + nb + 1;
    else if (nb <= - 4294967295)
        uit = 0;
    else
        uit = nb;
    out = ft_itoa_base(DIGIT, uit);
    return (out);
}

char    *print_p(unsigned long int ptr)
{
    char    *out;
    char    *tmp;

    out = ft_calloc(1, 3);
    out[0] = '0';
    out[1] = 'x';
    tmp = ft_itoa_base(HEXCAP, ptr);
    out = ft_strjoin(out, tmp);
    return (out);
}

char    *print_x(int nb, int iscap)
{
    char    *out;

    if (iscap > 0)
        out = ft_itoa_base(HEXCAP, nb);
    else
        out = ft_itoa_base(HEXLO, nb);
    return (out); 
}