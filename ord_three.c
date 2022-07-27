/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:50:18 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 10:50:35 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ord_three(t_control *ctr)
{
	if (ctr->stack_a->content < ctr->stack_a->next->content)
	{
		if (ctr->stack_a->content < ctr->stack_a->next->next->content)
		{
			ft_rrotate(ctr, 'a');
			ft_swap(ctr, 'a');
		}
		else
			ft_rrotate(ctr, 'a');
	}
	else
	{
		if (ctr->stack_a->content < ctr->stack_a->next->next->content)
			ft_swap(ctr, 'a');
		else
		{
			if (ctr->stack_a->next->next->content < ctr->stack_a->next->content)
			{
				ft_swap(ctr, 'a');
				ft_rrotate(ctr, 'a');
			}
			else
				ft_rotate(ctr, 'a');
		}
	}
}
