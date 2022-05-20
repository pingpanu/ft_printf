/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:09:20 by user              #+#    #+#             */
/*   Updated: 2022/05/20 14:52:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
void    ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void    ft_strcat(char *dst, const char *src);
int		ft_isdigit(int c);
int     ft_exist(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_itoa(int n);
char    *ft_uitoa_base(const char *str, unsigned int n);

#endif