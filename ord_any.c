/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_any.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:16:49 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/02 12:56:20 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_total_moves(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (aux)
	{
		aux->moves = aux->moves + aux->ra;
		aux->moves = aux->moves + aux->rb;
		aux->moves = aux->moves + aux->rr;
		aux->moves = aux->moves + aux->rra;
		aux->moves = aux->moves + aux->rrb;
		aux->moves = aux->moves + aux->rrr;
		aux = aux->next;
	}
}

void	ft_ord_any(t_control *control)
{
	t_list	*aux;

	aux = control->stack_a;
	ft_push(control, 'b');
	ft_push(control, 'b');
	ft_count_a_moves(control);
	ft_count_b_moves(control);
	ft_optimize_moves(control->stack_a);
	ft_total_moves(control->stack_a);
}
