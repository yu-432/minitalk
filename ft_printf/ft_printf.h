/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:28 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/31 18:21:06 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		if_per(const char *start, va_list ap, int count);
int		put_hex(unsigned long nb, int upper);
int		put_pointer(unsigned long p);
int		put_str(char *s);
int		put_c(int c);
int		put_unsign_int(unsigned int nb);
int		put_nbr(int n);

#endif