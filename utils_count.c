/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:37:36 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/02 12:38:48 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_search_index(int index, t_list *stack)
{
	t_list	*aux;
	int		i;
	int		max;

	i = 0;
	max = 0;
	aux = stack;
	while (aux)
	{
		if (aux->index > i && aux->index < index)
			i = aux->index;
		if (aux->index > max)
			max = aux->index;
		aux = aux->next;
	}
	if (!i)
		return (max);
	return (i);
}

void	ft_count_b_moves(t_control *control)
{
	t_list	*stack;
	t_list	*aux;
	int		index;

	stack = control->stack_a;
	while (stack)
	{
		aux = control->stack_b;
		index = ft_search_index(stack->index, control->stack_b);
		while (index != aux->index)
		{
			stack->rb++;
			aux = aux->next;
		}
		if (stack->rb > (control->b_size / 2))
		{
			stack->rb = 0;
			while (aux)
			{
				stack->rrb++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

void	ft_count_a_moves(t_control *control)
{
	t_list	*aux;
	t_list	*stack;

	stack = control->stack_a;
	while (stack)
	{
		aux = control->stack_a;
		while (stack->content != aux->content)
		{
			stack->ra++;
			aux = aux->next;
		}
		if (stack->ra > (control->a_size / 2))
		{
			stack->ra = 0;
			while (aux)
			{
				stack->rra++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

void	ft_optimize_moves(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (aux)
	{
		while (aux->ra && aux->rb)
		{
			aux->ra--;
			aux->rb--;
			aux->rr++;
		}
		while (aux->rra && aux->rrb)
		{
			aux->rra--;
			aux->rrb--;
			aux->rrr++;
		}
		aux = aux->next;
	}
}
