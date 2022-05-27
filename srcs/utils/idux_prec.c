/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idux_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:27:24 by user              #+#    #+#             */
/*   Updated: 2022/05/27 17:10:17 by pingpanu         ###   ########.fr       */
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
    }
    else
    {
        prc = iduput(str, f->precision, slen);
        if (!prc)
            return (NULL);
        if (str[0] == '-')
            prc[0] = '-';
    }
    f->len = ft_strlen(prc);
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