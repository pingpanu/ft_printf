/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:23:27 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/28 04:07:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only
#include <stdio.h>*/

static char *idu_zero_right(char *str, t_param *f);
static char	*align_left(char *str, t_param *f);
static char	*align_right(char *str, t_param *f);
char    *ft_dowidth(char *str, t_param *f)
{
    int     isnum;

    isnum = 0;
    if (f->type != 's' || f->type != 'p')
        isnum = 1;
    if (f->minus == 1)
        str = align_left(str, f);
    else if (f->lead == '0' && isnum == 1 && *str != '\0')
        str = idu_zero_right(str, f);
    else
        str = align_right(str, f);
    if (!str)
        return (NULL);
    f->len = ft_strlen(str);
    return (str);
}

static char *align_left(char *str, t_param *f)
{
    char    *ret;
    int     ri;
    
    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    ri = 0;
    while (str[ri])
    {
        ret[ri] = str[ri];
        ri++;
    }
    while (ri < f->width)
        ret[ri++] = ' ';
    free(str);
    return (ret);
}

static char *align_right(char *str, t_param *f)
{
    char    *ret;
    int     ri;
    int     si;

    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    ri = f->width - 1;
    si = f->len - 1;
    while (si >= 0)
        ret[ri--] = str[si--];
    free(str);
    while (ri >= 0)
        ret[ri--] = ' ';
    return (ret);
}

static void width_zero(char *ret, char *str, t_param *f)
{
    int     ri;
    int     si;

    ri = f->width - 1;
    si = f->len - 1;
    while (si >= 0)
    {
        if (str[si] == '-' || str[si] == '+' || str[si] == ' ')
            break ;
        ret[ri--] = str[si--];
    }
    while (ri >= 0)
        ret[ri--] = '0';
    if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
        ret[0] = str[0];
}

static char *idu_zero_right(char *str, t_param *f)
{
    char    *ret;

    if (f->dot == 1 && f->width > f->precision)
    {
        f->lead = ' ';
        ret = align_right(str, f);
        return (ret);
    }
    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    
    width_zero(ret, str, f);
    free (str);
    return (ret);
}

/*for test only
int main()
{
    char    *result;
    char    *buf;
    t_param f;

    f.lead = ' ';
    f.type = 'i';
    f.width = 10;
    f.minus = 1;
    f.len = 7;
    buf = ft_strdup("winter");
    result = ft_dowidth(buf, &f);
    printf("|%s|\n", result);
    free(result);
    return (0);
}*/