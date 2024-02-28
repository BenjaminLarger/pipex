/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ft_print_hex_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:57:52 by blarger           #+#    #+#             */
/*   Updated: 2024/01/12 18:59:39 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_to_hex_up(int hex_len, unsigned long long ptr_val, char *hex_str)
{
	int	i;
	int	res;

	res = 0;
	i = hex_len - 1;
	while (i >= 0)
	{
		res = ptr_val % 16;
		if (res < 10)
			hex_str[i] = '0' + res;
		else
			hex_str[i] = 'A' + (res - 10);
		ptr_val = ptr_val / 16;
		i--;
	}
	hex_str[hex_len] = '\0';
	return (hex_str);
}

int	ft_print_hex_up(unsigned int decimal)
{
	int					hex_len;
	char				*hex_str;

	hex_len = get_hex_len(decimal);
	hex_str = malloc((hex_len + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	conv_to_hex_up(hex_len, decimal, hex_str);
	ft_putstr_fd(hex_str, 1);
	free(hex_str);
	return (hex_len);
}

/* int main()
{
	ft_print_hex_up(-1);
	printf("\n%X\n", -1);
	
} */