/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:12:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/06 19:13:45 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(long number)
{
	size_t	size;

	if (number < 0)
		size = 1;
	else
		size = 0;
	while (1)
	{
		number /= 10;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	number;
	char	*array;
	size_t	size;

	number = n;
	size = get_size(n);
	array = (char *)malloc(size + 1);
	if (!(array))
		return (NULL);
	if (number < 0)
	{
		array[0] = '-';
		number *= -1;
	}
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = (number % 10) + '0';
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}
