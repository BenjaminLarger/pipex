/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:55:46 by blarger           #+#    #+#             */
/*   Updated: 2024/01/21 16:55:47 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (char *)malloc(count * size);
	if (!array)
		return (0);
	while (i < count * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
