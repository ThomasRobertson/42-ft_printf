/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:20:04 by troberts          #+#    #+#             */
/*   Updated: 2022/06/05 22:16:55 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	get_char(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	return (c);
}

int	print_char(va_list args)
{
	char	c;

	c = get_char(args);
	ft_putchar_fd(c, 1);
	return (LEN_CHAR);
}
