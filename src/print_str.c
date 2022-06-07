/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:27:14 by troberts          #+#    #+#             */
/*   Updated: 2022/06/05 22:17:24 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (str);
}

int	print_str(va_list args)
{
	char	*str;

	str = get_str(args);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
