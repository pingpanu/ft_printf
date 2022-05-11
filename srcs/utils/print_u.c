/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:38:07 by user              #+#    #+#             */
/*   Updated: 2022/05/10 21:43:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/

char    *ft_uitoa_base(const char *str, unsigned int n);

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