/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:05:51 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/13 15:05:55 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void    reset_param(t_param *f)
{
    f->minus = 0;
    f->plus = 0;
    f->space = 0;
    f->hash = 0;
    f->lead = ' ';
    f->dot = 0;
    f->width = 0;
    f->precision = 0;
    f-> type = 0;
}

t_param get_params(const char *fmt, t_param *f, int *i)
{
    reset_param(f);
    while(f->type == 0)
    {
        if (fmt[*i] == '-')
            f->minus = 1;
        if (fmt[*i] == '+')
            f->plus = 1;
        if (fmt[*i] == ' ')
            f->space = 1;
        if (f->width == 0 && f->dot == 0 && fmt[*i] == '0')
            f->lead = '0';
        if (fmt[*i] == '.')
            f->dot = 1;
        if (fmt[*i] == 0 && ft_isdigit(fmt[*i]))
            f->width = (f->width * 10) + (fmt[*i] - '0');
        if (fmt[*i] == 1 && ft_isdigit(fmt[*i]))
            f->precision = (f->precision * 10) + (fmt[*i] - '0');
        if (ft_exist(SPECS, fmt[*i]))
            f->type = fmt[*i];
        (*i)++;
    }
    return (*f);
}