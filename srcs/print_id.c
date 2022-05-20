/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:16 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/20 14:54:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>

static char *id_flag(int nbr, t_param *f);
static int  id_prc(t_param f, char *str);
int    print_id(int nbr, t_param f)
{
    char    *buf;
    char    *out;
    int         len;

    if (f->dot == 1 && f->precision == 0 && nbr == 0)
        return (0);
    buf = id_flag(nbr, &f);
    if (!buf)
        return (0);
    if (f.precision > ft_strlen(buf))
    {
        len = id_prc(f, buf);
        free(buf);
        return (len);
    }
    out = ft_dowidth(f, buf);
    free(buf);
    len = printstr(out);
    free(out);
    return(len);
}

static char *id_flag(int nbr, t_param *f)
{
    char    *buf;
    char    *out;

    buf = ft_itoa(nbr);
    if (!buf)
        return (NULL);
    if ((f->plus || f->space) && buf[0] != '-')
    {
        out = ft_calloc(1 (ft_strlen(buf) + 1));
        out[0] = putflag(f);
        ft_strcat(out, buf);
        free(buf);
        return (out);
    }
    return (buf);
}

static int  id_prc(t_param f, char *str)
{
    char    *out

    if (f.)
}

/*for test only*/
int main()
{
    t_param f;
    int     len;

    f.type = 'd';
    f.dot = 1;
    f.plus = 1;
    f.space = 0;
    f.precision = 0;
    len = print_id(0, f);
    printf("\n");
    printf("%d\n",len);
    return (0);
}