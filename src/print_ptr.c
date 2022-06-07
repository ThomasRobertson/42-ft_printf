/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:00:55 by troberts          #+#    #+#             */
/*   Updated: 2022/06/06 02:18:22 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_ptr(va_list args)
{
	size_t	ptr;

	ptr = va_arg(args, size_t);
	return (ft_uitoa(ptr, 16));
}

int	print_ptr(va_list args)
{
	char	*str;
	int		len;

	str = get_ptr(args);
	if (str == NULL)
	{
		write(0, "ERROR MALLOC", 13);
		return (PRINTF_ERROR_CODE);
	}
	else if (ft_strcmp(str, "0") == 0)
	{
		write (1, "(nil)", 5);
		free(str);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_strlen(str) + 2;
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}