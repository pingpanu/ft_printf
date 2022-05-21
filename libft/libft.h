/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:09:20 by user              #+#    #+#             */
/*   Updated: 2022/05/21 20:26:46 by pingpanu         ###   ########.fr       */
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
int		ft_isdigit(int c);
int     ft_exist(const char *str, char c);
char    *ft_strcat(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char    *ft_itoa(int n);
char    *ft_uitoa_base(const char *str, unsigned int n);

#endif