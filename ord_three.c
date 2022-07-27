/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:50:18 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 12:20:36 by amarzana         ###   ########.fr       */
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

static void	ft_push_min(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;
	int		mov_num;

	aux = control->stack_a;
	stack = control->stack_a;
	check = 0;
	mov_num = 0;
	while (stack)
	{
		check = 0;
		aux = control->stack_a;
		while (aux)
		{
			if (stack->content > aux->content)
				check = 1;
			aux = aux->next;
		}
		if (check == 0)
		{
			while (mov_num--)
				ft_rotate(control, 'a');
			ft_push(control, 'a');
			break ;
		}
		stack = stack->next;
		mov_num++;
	}
}

void	ft_ord_five(t_control *ctr)
{
	ft_push_min(ctr);
	ft_push_min(ctr);
	ft_ord_three(ctr);
	ft_push(ctr, 'b');
	ft_push(ctr, 'b');
}
