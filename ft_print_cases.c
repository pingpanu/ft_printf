/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:17:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/06 22:14:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     print_c(int c)
{
    int i;

    ft_putchar_fd(c, 1);
    i += 1;
    return (i); 
}

int    print_s(char *str)
{
    int len;

    ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    return (len);
}

int     print_num(int n)
{
    int len;
    
}