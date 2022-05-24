/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:08:06 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/24 23:27:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>

char    *print_u(unsigned int nb, t_param f)
{
    char    *out;

    if (f.dot && f.precision == 0 && nb == 0)
        return (0);
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
/*for test only*/
int main()
{
    t_param f;
    char    *out;

    f.type = 'u';
    f.dot = 1;
    f.precision = 0;
    out = print_u(250, &f);
    printf("%s\n",out);
    return (0);
}