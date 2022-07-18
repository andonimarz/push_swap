/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:54:42 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/18 17:07:51 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_atoi_check(const char *str, int *error)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			*error = 1;
		num = num * 10 + (str[i++] - 48);
	}
	if (num < INT_MIN || num > INT_MAX)
		*error = 1;
	return (num * sign);
}
