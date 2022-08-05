/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:54:42 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 13:01:59 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

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
	if (!str[i])
		*error = 1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			*error = 1;
		num = num * 10 + (str[i++] - 48);
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		*error = 1;
	return (num * sign);
}
