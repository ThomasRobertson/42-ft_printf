/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:59:49 by troberts          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_unsigned(va_list args)
{
	unsigned int	integer;

	integer = va_arg(args, unsigned int);
	return (ft_uitoa(integer, 10));
}

int	print_unsigned(va_list args)
{
	char	*str;
	int		len;

	str = get_unsigned(args);
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
