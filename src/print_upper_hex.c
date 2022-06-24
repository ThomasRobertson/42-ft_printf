/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upper_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:51:49 by troberts          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:28 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_upper_hex(va_list args)
{
	unsigned int	number;
	char			*str;
	size_t			i;

	i = 0;
	number = va_arg(args, unsigned int);
	str = ft_uitoa(number, 16);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	print_upper_hex(va_list args)
{
	char	*str;
	int		len;

	str = get_upper_hex(args);
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
