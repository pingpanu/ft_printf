/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numprc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:35:43 by user              #+#    #+#             */
/*   Updated: 2022/04/30 14:43:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *fillnumprc(char *out, char *buf)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (out[0] == '-' || out[0] == '+' || out[0] == ' ')
        i = 1;
    while ((i < ft_strlen(buf)) && out[i])
        out[i++] = '0';
    while (out[i] && buf[j])
        out[i++] =  buf[j++];
    out[i] = '\0';
    return (out);
}