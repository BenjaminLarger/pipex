/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:23:15 by blarger           #+#    #+#             */
/*   Updated: 2023/12/14 12:38:00 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 34 && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[0] != 34)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += input_type(str[++i], args);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*  int	main()
{
	ft_printf("%u\n", 2424939277);
	printf("%ld\n", 2424939277);
} */
