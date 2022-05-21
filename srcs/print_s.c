/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:07:57 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/21 21:53:50 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*for test only*/
#include <stdio.h>

static int  s_flag(t_param f, char *str);
static int  s_cut(t_param f, char *str);
static int  s_expand(t_param f, char *str);
static int  s_cande(t_param f, char *str);
int     print_s(char *str, t_param f)
{
    f.len = ft_strlen(str);
    if (!str || (f.dot && f.precision == 0))
        f.len = printstr(nostr_handle(f.precision));
    else if (f.space)
        f.len = s_flag(f, str);
    else if (f.precision < f.len)
        f.len = s_cut(f, str);
    else if (f.width > f.len)
        f.len = s_expand(f, str);
    else
        f.len = printstr(str);
    return (f.len);
}

static int  s_flag(t_param f, char *str)
{
    char    *flag;
    
    if (f.precision < (int)ft_strlen(str))
    {
        flag = strcut(f.precision, str);
        flag = ft_doflag(flag, &f);
        if (f.width > (int)ft_strlen(flag))
            flag = ft_dowidth(flag, &f);
        f.len = printstr(flag);
    }
    else if (f.width > (int)ft_strlen(str) + 1)
    {
        flag = ft_dowidth(str, &f);
        f.len = printstr(flag);
    }
    else
    {
        flag = ft_doflag(str, &f);
        f.len = printstr(flag);
    }
    free(flag);
    return (f.len);
} 

static int  s_cut(t_param f, char *str)
{
    int         len;
    char    *cut;

    cut = ft_calloc(1, (f.precision + 1));
    if (!cut)
        return (0);
    ft_memcpy(cut, str, f.precision);
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

/*for test only*/
int main()
{
    t_param f;
    int         len;

    f.dot = 1;
    f.precision = 10;
    f.width = 15;
    f.lead = ' ';
    f.space = 0;
    len = print_s("winterfell", f);
    printf("\n");
    printf("%d\n",len);
    return (0);
}