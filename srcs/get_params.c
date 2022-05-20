/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:05:51 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/19 23:35:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only
#include <stdio.h>*/

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

t_param get_params(const char *fmt, t_param f, int *i)
{
    reset_param(&f);
    while(f.type == 0)
    {
        if (fmt[*i] == '-')
            f.minus = 1;
        if (fmt[*i] == '+')
            f.plus = 1;
        if (fmt[*i] == ' ')
            f.space = 1;
        if (f.width == 0 && f.dot == 0 && fmt[*i] == '0')
            f.lead = '0';
        if (fmt[*i] == '.')
            f.dot = 1;
        if (f.dot == 0 && ft_isdigit(fmt[*i]))
            f.width = (f.width * 10) + (fmt[*i] - '0');
        if (f.dot == 1 && ft_isdigit(fmt[*i]))
            f.precision = (f.precision * 10) + (fmt[*i] - '0');
        if (ft_exist(SPECS, fmt[*i]))
            f.type = fmt[*i];
        (*i)++;
    }
    return (f);
}

/*for test only
int main (int argc, char **argv)
{
    t_param f;
    int i;

    if (argc != 3)
        return (0);
    i = atoi(argv[2]);
    f = get_params(argv[1], f, &i);
    printf("f.minus = %i\n", f.minus);
    printf("f.plus = %i\n", f.plus);
    printf("f.space = %i\n", f.space);
    printf("f.hash = %i\n", f.hash);
    printf("f.lead = %c\n", f.lead);
    printf("f.dot = %i\n", f.dot);
    printf("f.width = %d\n", f.width);
    printf("f.precision = %d\n", f.precision);
    printf("f.type = %c\n", f.type);
    return (0);
}*/