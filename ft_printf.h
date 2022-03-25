/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:33 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/25 16:47:53 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
/*function in main printf*/
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *fmt, va_list ap);
static int	ft_print_aux(const char *fmt, va_list ap, int len);
/*function in print_cases*/
typedef int	(*ft_print_cases_f) (const char *fmt, va_list ap, int len);
int		printf_char(const char *fmt, va_list ap, int len);
int		printf_num(const char *fmt, va_list ap, int len);
int		printf_oc(const char *fmt, va_list ap, int len);
int		printf_dec(const char *fmt, va_list ap, int len);
int		printf_hex(const char *fmt, va_list ap, int len);
int		printf_hexup(const char *fmt, va_list ap, int len);
int		printf_string(const char *fmt, va_list ap, int len);
#endif
