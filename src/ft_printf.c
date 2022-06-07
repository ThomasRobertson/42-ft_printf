/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:02:17 by troberts          #+#    #+#             */
/*   Updated: 2022/06/07 18:30:48 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_args(va_list args, const char *fmt)
{
	if (fmt[0] == '%')
		return (write(1, "%", 1));
	else if (fmt[0] == 'i' || fmt[0] == 'd')
		return (print_int(args));
	else if (fmt[0] == 'c')
		return (print_char(args));
	else if (fmt[0] == 's')
		return (print_str(args));
	else if (fmt[0] == 'u')
		return (print_unsigned(args));
	else if (fmt[0] == 'x')
		return (print_lower_hex(args));
	else if (fmt[0] == 'X')
		return (print_upper_hex(args));
	else if (fmt[0] == 'p')
		return (print_ptr(args));
	else
		return (-1);
}

int	scan_args(va_list args, const char *fmt)
{
	int	i;
	int	nbr_print;
	int	tmp;

	i = 0;
	nbr_print = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] != '\0')
			{
				tmp = process_args(args, fmt + i);
				if (tmp == PRINTF_ERROR_CODE)
					return (PRINTF_ERROR_CODE);
				nbr_print += tmp;
			}
		}
		else
			nbr_print += write(1, &fmt[i], 1);
		i++;
	}
	return (nbr_print);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		nbr_print;

	va_start(args, fmt);
	nbr_print = scan_args(args, fmt);
	va_end(args);
	if (nbr_print == PRINTF_ERROR_CODE)
		return (PRINTF_ERROR_CODE);
	return (nbr_print);
}
