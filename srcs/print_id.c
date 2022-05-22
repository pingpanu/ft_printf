/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:16 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/22 23:56:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>

int    print_id(int nbr, t_param f)
{
    char    *out;

    if (f.dot && f.precision == 0 && nbr == 0)
        return (0);
    out = ft_itoa(nbr);
    if (!out)
        return (0);
    f.len = ft_strlen(out);
    if (f.dot && f.precision > f.len)
        out = idux_prec(out, &f);
    if (f.space || f.plus)
        out = ft_doflag(out, &f);
    if (f.width > f.len)
        out = ft_dowidth(out, &f);
    f.len = printstr(out);
    free(out);
    return (f.len);
}

/*for test only*/
int main()
{
    t_param f;
    int     len;

    f.type = 'd';
    f.dot = 0;
    f.plus = 1;
    f.space = 0;
    f.precision = 0;
    f.width = 0;
    len = print_id(42, f);
    printf("\n");
    printf("%d\n",len);
    return (0);
}