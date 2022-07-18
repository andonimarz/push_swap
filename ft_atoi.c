/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:54:42 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/18 16:25:54 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void	ft_check_int(long num)
{
	if (num < INT_MIN || num > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit(0);
	}	
}

int	ft_atoi_check(const char *str)
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
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		num = num * 10 + (str[i++] - 48);
	}
	ft_check_int(num * sign);
	return (num * sign);
}
