/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:58 by user              #+#    #+#             */
/*   Updated: 2022/04/01 17:06:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void  reset_param(t_param *f)
{
    f->minus = 0;
    f->plus = 0;
    f->space = 0;
    f->hash = 0;
    f->zero = 0;
    f->point = 0;
    f->dot = 0;
    f->width = 0;
    f->precision = 0;
    f->type = 0;
}

t_param get_params(const char *fmt, t_param *f, int *i)
{
    reset_param(f);
    while (f->type == 0)
    {
        if (fmt[*i] == '-')
            f->minus = 1;
        if (fmt[*i] == '+')
            f->plus = 1;
        if (fmt[*i] == ' ')
            f->space += 1;
        if (fmt[*i] == '*')
            f->point == 1;
        if (fmt[*i] == '.')
            f->dot == 1;
        if (f->dot == 0 && ft_isdigit(fmt[*i]))
            f->width = (f->width * 10) + (fmt[*i] - '0');
        if (f->dot == 1 && ft_isdigit(fmt[*i]))
            f->width = (f->width * 10) + (fmt[*i] - '0');
        if (ft_isspecs(fmt[*i]))
            f->type = fmt[*i];
    }
    return (*f);
}