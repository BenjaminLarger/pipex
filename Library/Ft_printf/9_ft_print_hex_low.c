/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_ft_print_hex_low.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:34 by blarger           #+#    #+#             */
/*   Updated: 2024/01/12 19:02:33 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_len_unsign(unsigned int str)
{
	int	count;

	if (str == 0)
		return (1);
	count = 0;
	if (!str)
		return (0);
	while (str)
	{
		count++;
		str >>= 4;
	}
	return (count);
}

int	ft_print_hex_low(unsigned int decimal)
{
	int					hex_len;
	char				*hex_str;

	hex_len = get_hex_len(decimal);
	hex_str = malloc((hex_len + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	conv_hex_low(hex_len, decimal, hex_str);
	ft_putstr_fd(hex_str, 1);
	free(hex_str);
	return (hex_len);
}

/* int main()
{
	ft_print_hex_low(-1);
	printf("\n%x\n", -1);
} */