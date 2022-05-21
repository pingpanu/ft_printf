/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:41:57 by user              #+#    #+#             */
/*   Updated: 2022/05/21 20:29:03 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strcat(char *dst, const char *src)
{
    int     i;
    int     offset;

    i = 0;
    offset = ft_strlen(dst);
    while (src[i] && dst[offset + i])
    {
        dst[offset + i] = src[i];
        i++;
    }
    return (dst);
}