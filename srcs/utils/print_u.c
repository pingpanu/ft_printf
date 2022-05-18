/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:08:06 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/18 16:09:07 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

char    *print_u(unsigned int nb, t_param *f)
{
    char    *buf;
    char    *out;
    int             len;
    int             blen;

    if (f->dot && f->precision == 0 && nb == 0)
        return ("");
    buf = ft_uitoa_base(DIGIT, nb);
    blen = ft_strlen(buf);
    len = 0;
    if (f->precision <= blen)
        return (buf);
    if (f->precision > blen)
        len = f->precision;
    out = idput(buf, len, (blen - 1));
    free(buf);
    if (!out)
        return (NULL);
    return (out);
}
/*for test only
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
}*/