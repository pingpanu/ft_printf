/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:23:27 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/24 23:15:52 by user             ###   ########.fr       */
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
    if (f->type == 'i'|| f->type == 'd' || f->type == 'u')
        isnum = 1;
    if (f->minus == 1)
        str = align_left(str, f);
    if (f->lead == '0' && isnum == 1)
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
    int     si;
    
    ret = ft_calloc(1, (f->width + 1));
    if (!ret)
        return (NULL);
    ri = 0;
    si = 0;
    while (str[si])
        ret[ri++] = str[si++];
    free (str);
    while (ret[ri])
        ret[ri++] = ' ';
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

static char *idu_zero_right(char *str, t_param *f)
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
    f.type = 'i';
    f.width = 20;
    f.minus = 0;
    f.len = 5;
    result = ft_dowidth("+0042", &f);
    printf("%s\n", result);
    return (0);
}*/