/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:57 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/20 14:20:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only*/
#include <stdio.h>

static int  s_cut(int precision, char *str);
static int  s_expand(t_param f, char *str);
static int  s_cande(t_param f, char *str);
int     print_s(char *str, t_param f)
{
    int         len;
    
    if (!str || (f.dot && f.precision == 0))
        len = printstr(nostr_handle(f.precision));
    if (f.dot && f.precision < (int)ft_strlen(str))
    {
        if (f.width > f.precision)
            len = s_cande(f, str);
        else
            len = s_cut(f.precision, str);
    }
    else if (f.width > (int)ft_strlen(str))
        len = s_expand(f, str);
    else
        len = printstr(str);
    return (len);
}

static int  s_cut(int precision, char *str)
{
    int         len;
    char    *cut;

    cut = ft_calloc(1, (precision + 1));
    if (!cut)
        return (0);
    ft_memcpy(cut, str, precision);
    len = printstr(cut);
    free(cut);
    return (len);
}

static int  s_expand(t_param f, char *str)
{
    int         len;
    char    *expand;

    expand = ft_dowidth(str, &f);
    if (!expand)
        return (0);
    len = printstr(expand);
    free(expand);
    return (len);
}

static int  s_cande(t_param f, char *str)
{
    char    *cut;
    char    *expand;
    int     len;

    cut = ft_calloc(1, (f.precision + 1));
    if (!cut)
        return (0);
    ft_memcpy(cut, str, f.precision);
    expand = ft_dowidth(cut, &f);
    free (cut);
    if (!expand)
        return (0);
    len = printstr(expand);
    free(expand);
    return (len);
}

/*for test only
int main()
{
    t_param f;
    int         len;

    f.dot = 1;
    f.precision = 10;
    f.width = 15;
    f.lead = ' ';
    len = print_s("winterfell", f);
    printf("\n");
    printf("%d\n",len);
    return (0);
}*/