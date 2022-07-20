/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:54:15 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/20 14:55:37 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_job(t_list *stack)
{
	int		aux;

	aux = stack->content;
	stack->content = stack->next->content;
	stack->next->content = aux;
}

void	ft_swap(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "sa\n", 3);
		ft_swap_job(control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "sb\n", 3);
		ft_swap_job(control->stack_b);
	}
	else if (c == 's')
	{
		write(1, "ss\n", 3);
		ft_swap_job(control->stack_a);
		ft_swap_job(control->stack_b);
	}
}

void	ft_rotate_job(t_list *stack)
{
	while (stack->next)
	{
		ft_swap_job(stack);
		stack = stack->next;
	}
}

void	ft_rotate(t_control *control, char c)
{
	if (c == 'a')
	{
		write(1, "ra\n", 3);
		ft_rotate_job(control->stack_a);
	}
	else if (c == 'b')
	{
		write(1, "rb\n", 3);
		ft_rotate_job(control->stack_b);
	}
	else if (c == 'r')
	{
		write(1, "rr\n", 3);
		ft_rotate_job(control->stack_a);
		ft_rotate_job(control->stack_b);
	}
}
