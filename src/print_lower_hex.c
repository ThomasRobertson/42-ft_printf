/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lower_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:28:05 by troberts          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:12 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_lower_hex(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	return (ft_uitoa(number, 16));
}

int	print_lower_hex(va_list args)
{
	char	*str;
	int		len;

	str = get_lower_hex(args);
	if (str == NULL)
	{
		write(0, "ERROR MALLOC", 13);
		return (PRINTF_ERROR_CODE);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
