/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:46:35 by blarger           #+#    #+#             */
/*   Updated: 2024/02/13 12:57:21 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Functions in order
int		ft_printf(const char *str, ...);
int		input_type(const char c, va_list input);
int		ft_putchar(int c);
int		ft_putstr_fd(char *str, char fd);
int		ft_ptr_to_hex(void *str);
int		ft_putnbr_dec(double n);
int		ft_putnbr(int n);
int		ft_putnbr_dec_unsigned(double n);
int		ft_print_hex_low(unsigned int decimal);
int		ft_print_hex_up(unsigned int decimal);
//Utils
int		ft_len_int(int n);
int		get_hex_len(unsigned long str);
char	*conv_hex_low(int hex_len, unsigned long ptr_val, char *hex_str);
#endif
