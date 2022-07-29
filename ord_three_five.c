/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_three_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:50:18 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/29 11:17:33 by amarzana         ###   ########.fr       */
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

static void	ft_push_min_job(int mov_num, t_control *control)
{
	if (mov_num < 3)
		while (mov_num--)
			ft_rotate(control, 'a');
	else
	{
		if (mov_num == control->a_size - 2)
		{
			ft_rrotate(control, 'a');
			ft_rrotate(control, 'a');
		}
		if (mov_num == control->a_size - 1)
			ft_rrotate(control, 'a');
	}
	ft_push(control, 'b');
}

static void	ft_push_min(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		check;
	int		mov_num;

	stack = control->stack_a;
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
			ft_push_min_job(mov_num, control);
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
	ft_check_order(ctr);
	if (ctr->error == 0)
		ft_ord_three(ctr);
	ft_push(ctr, 'a');
	ft_push(ctr, 'a');
}
