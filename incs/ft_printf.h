/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:33 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/20 23:52:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define SPECS  "cspdiuxX%"
# define DIGIT  "0123456789"
# define HEXLO  "0123456789abcdef"
# define HEXCAP "0123456789ABCDEF"

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
t_param get_params(const char *fmt, t_param *f, int *i);
char    *ft_putspecs(t_param *f, va_list ap);
char    *ft_printflag(char *buf, t_param *f);
char    *ft_printwidth (char *str, t_param *f);
char    *ft_dowidth(char *str, t_param *f);
/*function in print_cases*/
char    *print_c(char c);
char    *print_s(char *str);
char    *print_id(int nbr);
char    *print_u(int nb);
char    *print_p(unsigned long int ptr);
char    *print_x(int nb, int iscap);
#endif
