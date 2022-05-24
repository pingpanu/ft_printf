/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idux_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:27:24 by user              #+#    #+#             */
/*   Updated: 2022/05/24 23:14:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char    *idux_prec(char *str, t_param *f)
{
    char    *prc;
    int     slen;

    slen = f->len - 1;
    if (f->type == 'x' || f->type =='X')
    {
        prc = xput(str, f->precision, slen);
        if (!prc)
            return (NULL);
        return (prc);
    }
    prc = iduput(str, f->precision, slen);
    if (!prc)
        return (NULL);
    if (str[0] == '-')
        prc[0] = '-';
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