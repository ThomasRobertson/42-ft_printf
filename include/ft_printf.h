/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:04:22 by troberts          #+#    #+#             */
/*   Updated: 2022/06/07 18:31:36 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define LEN_CHAR 1
# define PRINTF_ERROR_CODE -1

/* ************************************************************************** */
/*                            HELPERS TO CONVERSION                           */
/* ************************************************************************** */

size_t			u_nbrlen(size_t n, int base_lenght);
char			*ft_uitoa(size_t n, int base_lenght);

/* ************************************************************************** */
/*                                 CONVERSION                                 */
/* ************************************************************************** */

char			*get_int(va_list args);
int				print_int(va_list args);
unsigned char	get_char(va_list args);
int				print_char(va_list args);
char			*get_str(va_list args);
int				print_str(va_list args);
char			*get_unsigned(va_list args);
int				print_unsigned(va_list args);
char			*get_lower_hex(va_list args);
int				print_lower_hex(va_list args);
char			*get_upper_hex(va_list args);
int				print_upper_hex(va_list args);
char			*get_ptr(va_list args);
int				print_ptr(va_list args);

/* ************************************************************************** */
/*                                	FT_PRINTF                                 */
/* ************************************************************************** */

int				ft_printf(const char *fmt, ...);

#endif
