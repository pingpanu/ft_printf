/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idux_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:27:24 by user              #+#    #+#             */
/*   Updated: 2022/05/28 02:12:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *idux_prec(char *str, t_param *f)
{
    char    *prc;

    if (f->type == 'x' || f->type =='X')
    {
        prc = xput(str, f->precision, f->len - 1);
        if (!prc)
            return (NULL);
    }
    else
    {
        prc = iduput(str, f->precision, f->len - 1);
        if (!prc)
            return (NULL);
        if (str[0] == '-')
            prc[0] = '-';
    }
    f->len = ft_strlen(prc);
    free(str);
    return (prc);
}

/*for test only
int main()
{
    char    str[4] = "-042";
    char    *out;
    t_param     f;

    f.precision = 6;
    f.type = 'i';
    out = idux_prec(str, &f);
    printf("%s\n",out);
    free(out);
    return (0);
}*/