/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:57 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/27 15:14:16 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only
#include <stdio.h>*/

static char *strcut(char *str, t_param *f);
int     print_s(char *str, t_param f)
{
    char    *ret;

    f.len = ft_strlen(str);
    if (!str || (f.dot && f.precision == 0))
        f.len = printstr(nostr_handle(f.precision));
    ret = ft_strdup(str);
    if (f.dot && f.precision < f.len)
        ret = strcut(ret, &f);
    if (f.space == 1)
        ret = ft_doflag(ret, &f);
    if (f.width > f.len)
        ret = ft_dowidth(ret, &f);
    f.len = printstr(ret);
    free(ret);
    return (f.len);
}

static char *strcut(char *str, t_param *f)
{
    char    *out;
    
    out = ft_calloc(1, f->precision + 1);
    if (!out)
        return (NULL);
    ft_memcpy(out, str, f->precision);
    free(str);
    f->len = ft_strlen(out);
    return (out);
}

/*for test only
int main()
{
    t_param f;
    int         len;

    f.type = 's';
    f.dot = 0;
    f.precision = 5;
    f.width = 15;
    f.lead = ' ';
    f.space = 0;
    f.minus = 0;
    len = print_s("winterfell", f);
    printf("\n");
    printf("%d\n",len);
    return (0);
}*/