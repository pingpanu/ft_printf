/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:41:30 by user              #+#    #+#             */
/*   Updated: 2022/04/16 20:50:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int ft_putall(t_param f, va_list ap)
{
    char    *buf; //placeholder for printed ap
    char    *out; //buf manipulated per flag, width, and precision
    int         len;

    len = 0;
    buf = ft_putspecs(&f, ap);
    if (f.type == 'f' || f.type == 'p')
    {
        len = ft_strlen(buf);
        ft_putstr_fd(buf, 1);
        free(buf);
        return (len);
    }
    if (f.type != 'c' && f.type != 's')
        out = ft_printflag(out, f);
    out = ft_printwidth(buf, f);
    free(buf);
    
    len = ft_strlen(out);
    ft_putstr_fd(out, 1);
    free(out);
    return (len);
}