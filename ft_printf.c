/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/04/04 23:21:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h> /*for test only*/
#include <unistd.h>
#include <stdarg.h>

/*char	get_flag_string(const char *fmt, int *i)
{
	char	*flag;
	int		j;
	int		len;

	j = 0;
	while (!ft_strchr(SPECS, fmt[*i]))
		len++;
	flag = malloc(sizeof(char) * (len + 2));

	return (flag);
}*/

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int			done;
	int			i; //pointer to format
	t_param		f; //format parameters after %

	i = 0;
	done = -1;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], 1);
			done++;
		}
		/*else
		{
			f = get_params(format, &f, &i);
			done += ft_putspecs(&f, arg);
		}
		*/
	}
	va_end (arg);
	return (done);
}

int main(void)
{
	printf("Vouz avez peri\n");
	ft_printf("Vouz avez peri\n");
	printf("%3dzc\n", 0);
	printf("%-+3dzc\n", 0);
	printf("%10.3snk\n","he");
	printf("%-10.3snk\n","he");
	return (0);
}