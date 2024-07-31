/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:34:39 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/09 16:11:53 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_per(const char *format, va_list ap, int count)
{
	if (*format == 'c')
		count += put_c(va_arg(ap, int));
	else if (*format == 's')
		count += put_str(va_arg(ap, char *));
	else if (*format == 'p')
		count += put_pointer((unsigned long)va_arg(ap, void *));
	else if (*format == 'd' || *format == 'i')
		count += put_nbr(va_arg(ap, int));
	else if (*format == 'u')
		count += put_unsign_int(va_arg(ap, unsigned int));
	else if (*format == 'x')
		count += put_hex(va_arg(ap, unsigned int), 0);
	else if (*format == 'X')
		count += put_hex(va_arg(ap, unsigned int), 1);
	else if (*format == '%')
		count += write(1, "%", 1);
	else if (*format != '\0')
		count += write(1, format, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			count += put_c(*format);
		else if (*format == '%')
		{
			format++;
			count = if_per(format, ap, count);
		}
		if (!*format)
			break ;
		format++;
	}
	va_end(ap);
	return (count);
}
