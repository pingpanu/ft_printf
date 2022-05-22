/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idux_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:55:11 by user              #+#    #+#             */
/*   Updated: 2022/05/22 22:55:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *idux_prc(char *str, t_param *f)
{
    char    *prc;

    if (f->type == 'x' || f->type =='X')
    {
        prc = xput(str, f->precision, ft_strlen(str) - 1);
        if (!prc)
            return (NULL);
        if (f->hash)
            prc[1] = f->type;
    }
    else
    {
        prc = idput(str, f->precision, ft_strlen(str) - 1);
        if (!prc)
           return (NULL);
        if (!ft_isdigit(str[0]))
            prc[0] = str[0];
    }
    return (prc);
}