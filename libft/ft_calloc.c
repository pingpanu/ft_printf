/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:03:48 by user              #+#    #+#             */
/*   Updated: 2022/03/04 23:41:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*alme;

	alme = malloc (count * size);
	if (!alme)
		return (NULL);
	ft_bzero (alme, count * size);
	return (alme);
}
