/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:21:35 by user              #+#    #+#             */
/*   Updated: 2022/02/26 14:21:20 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*ret;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc (sizeof(char) * (s1len + s2len +1));
	if (!join)
		return (NULL);
	ret = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (ret);
}
