/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:08:06 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/28 03:46:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>*/

int    print_u(unsigned int nb, t_param f)
{
    char    *out;

    if (f.dot && f.precision == 0 && nb == 0)
        out = ft_calloc(1, 1);
    else
        out = ft_uitoa_base(DIGIT, nb);
    if (!out)
        return (0);
    f.len = ft_strlen(out);
    if (f.dot && f.precision > f.len)
        out = idux_prec(out, &f);
    if (f.width > f.len)
        out = ft_dowidth(out, &f);
    f.len = printstr(out);
    free(out);
    return (f.len);
}
/*for test only
int main()
{
    t_param f;

    f.type = 'u';
    f.dot = 1;
    f.precision = 12;
    f.width = 20;
    f.len = print_u(2147483648, f);
    printf("\n%d\n",f.len);
    return (0);
}*/