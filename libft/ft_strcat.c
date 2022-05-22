/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:41:57 by user              #+#    #+#             */
/*   Updated: 2022/05/22 17:09:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strcat(char *dst, const char *src)
{
    int     i;
    int     offset;

    i = 0;
    offset = ft_strlen(dst);
    while (src[i])
        dst[offset++] = src[i++];
    return (dst);
}