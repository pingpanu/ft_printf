/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:33 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/08 16:16:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define SPECS  "cspdiuxX%"

typedef struct s_param
{
    int     minus;
    int     plus;
    int     space;
    int     hash;
    int     dot;
    int     width;
    int     precision;
    char    lead;
    char    type;
}               t_param;

/*function in main printf*/
int		    ft_printf(const char *format, ...);
int         ft_putall(t_param *f, va_list ap);
int		    ft_putspecs(t_param *f, va_list ap);
t_param get_params(const char *fmt, t_param *f, int *i);
/*function in print_cases*/
int		printf_char(const char *fmt, va_list ap, int len);
int		printf_num(const char *fmt, va_list ap, int len);
int		printf_oc(const char *fmt, va_list ap, int len);
int		printf_hex(const char *fmt, va_list ap, int len);
int		printf_hexup(const char *fmt, va_list ap, int len);
int		printf_string(const char *fmt, va_list ap, int len);
#endif
