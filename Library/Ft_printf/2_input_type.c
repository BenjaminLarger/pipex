/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_input_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:06:56 by blarger           #+#    #+#             */
/*   Updated: 2024/01/12 19:00:36 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	input_type(const char c, va_list input)
{
	if (c == 'c')
		return (ft_putchar(va_arg(input, int)));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(input, char *), 1));
	else if (c == 'p')
		return (ft_ptr_to_hex(va_arg(input, char *)));
	else if (c == 'd')
		return (ft_putnbr_dec(va_arg(input, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(input, int)));
	else if (c == 'u')
		return (ft_putnbr_dec_unsigned(va_arg(input, int)));
	else if (c == 'x')
		return (ft_print_hex_low(va_arg(input, int)));
	else if (c == 'X')
		return (ft_print_hex_up(va_arg(input, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
