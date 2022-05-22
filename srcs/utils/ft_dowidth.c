/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:23:27 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/22 22:35:08 by user             ###   ########.fr       */
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
    char    *wdt;
    int     isnum;

    isnum = 0;
    if (f->type == 'i'|| f->type == 'd' || f->type == 'u')
        isnum = 1;
    if (f->minus == 1)
        wdt = align_left(str, f);
    if (f->lead == '0' && isnum == 1)
        idu_zero_right(str, f);
    else
        wdt = align_right(str, f);
    if (!wdt)
        return (NULL);
    f->len = ft_strlen(wdt);
    return (wdt);
}

static char *align_left(char *str, t_param *f)
{
    char    *ret;
    int     ri;
    int     si;
    
    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    ri = 0;
    si = 0;
    while (str[si])
        ret[ri++] = str[si++];
    while (ret[ri])
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
    si = (int)ft_strlen(str) - 1;
    while (si >= 0)
        ret[ri--] = str[si--];
    while (ri >= 0)
        ret[ri--] = f->lead;
    free(str);
    return (ret);
}

static char *idu_zero_right(char *str, t_param *f)
{
    char    *ret;
    int     ri;
    int     si;

    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    ri = f->width - 1;
    si = (int)ft_strlen(str) - 1;
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
    free (str);
    return (ret);
}

/*for test only
int main()
{
    char *result;
    t_param f;

    f.lead = ' ';
    f.type = 's';
    f.width = 20;
    f.minus = 1;
    result = ft_dowidth("To the moon", &f);
    printf("%s\n", result);
    return (0);
}*/