/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:33 by pingpanu          #+#    #+#             */
/*   Updated: 2022/05/10 21:37:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
/*predefied constants*/
# define SPECS  "cspdiuxX%"
# define DIGIT  "0123456789"
# define HEXLO  "0123456789abcdef"
# define HEXCAP "0123456789ABCDEF"
/*to print null per LINUX or MAC*/
# ifndef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "(nil)"
#  define P_EMPTY_L 5
# else
#  define IS_LINUX 0
#  define OS "MAC"
#  define S_EMPTY "(null)"
#  define S_EMPTY_L 6
#  define P_EMPTY "0x0"
#  define P_EMPTY_L 3
# endif
/*struct for bonus part*/
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

/*function in main prinf*/
int		    ft_printf(const char *format, ...);
t_param get_params(const char *fmt, t_param *f, int *i);
char    *ft_putspecs(t_param *f, va_list ap);
char    *ft_dowidth(char *str, t_param *f);
/*function to print va_arg*/
char    *print_s(char *str, t_param *f);
char    *print_id(int nbr, t_param *f);
char    *print_u(unsigned int nb, t_param *f);
char    *print_p(unsigned long int ptr);
char    *print_x(unsigned int unb, t_param *f);
char    *idput(char *buf, int len, int blen);
char    *xput(char *buf, int len, int blen);
char    *nostr_handle(int prc);
char    putflag(t_param *f, int n);
int         print_c(char c, t_param *f);
#endif