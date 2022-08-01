/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_three_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:50:18 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/01 11:05:33 by amarzana         ###   ########.fr       */
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
	if (control->a_moves < 3)
		while (control->a_moves--)
			ft_rotate(control, 'a');
	else
	{
		if (control->a_moves == control->a_size - 2)
		{
			ft_rrotate(control, 'a');
			ft_rrotate(control, 'a');
		}
		if (control->a_moves == control->a_size - 1)
			ft_rrotate(control, 'a');
	}
	control->a_moves = 0;
	ft_push(control, 'b');
}

static void	ft_find_min(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;
	int		moves;

	stack = control->stack_a;
	moves = 0;
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
			control->a_moves = moves;
			break ;
		}
		stack = stack->next;
		moves++;
	}
}

void	ft_ord_five(t_control *ctr)
{
	ft_find_min(ctr);
	ft_push_min(ctr);
	ft_find_min(ctr);
	ft_push_min(ctr);
	if (ft_check_order(1, ctr))
		ft_ord_three(ctr);
	ft_push(ctr, 'a');
	ft_push(ctr, 'a');
}
