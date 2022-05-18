/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dowidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:23:27 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/18 16:03:59 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*for test only*/
#include <stdio.h>

static void	changestr(char *out, char *str);
static char	*align_left(char *str, int width);
static char	*align_right(char *str, t_param *f);

char    *ft_dowidth(char *str, t_param *f)
{
    char    *out;

    if (f->width <= (int)ft_strlen(str))
        return (str);
    if (f->minus == 1)
        out = align_left(str, f->width);
    else
        out = align_right(str, f);
    if (!out)
        return (NULL);
    if (f->lead == '0' && (f->type == 'i' || f->type == 'd'))
        changestr(out, str);
    return (out);
}

static char *align_left(char *str, int width)
{
    char    *ret;
    int     ri;
    int     si;
    ret = ft_calloc(1, (width + 1));
    if (!ret)
        return (NULL);
    ri = 0;
    si = 0;
    while (str[si])
        ret[ri++] = str[si++];
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
    si = (int)ft_strlen(str) - 1;
    while (si >= 0)
        ret[ri--] = str[si--];
    while (ri >= 0)
        ret[ri--] = f->lead;
    return (ret);
}

static void	changestr(char *out, char *str)
{
    int i;

    i = 1;
    if (str[0] == '-')
        out[0] = '-';
    while (out[i])
    {
        if (out[i] == '-')
            out[i] = '0';
        i++;
    }
}

/*for test only*/
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
}