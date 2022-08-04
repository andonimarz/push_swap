/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_any.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:16:49 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/04 13:03:46 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_total_moves(t_list *stack)
{
	t_list	*aux;
	int		min_moves;

	aux = stack;
	min_moves = INT_MAX;
	while (aux)
	{
		aux->moves = aux->moves + aux->ra;
		aux->moves = aux->moves + aux->rb;
		aux->moves = aux->moves + aux->rr;
		aux->moves = aux->moves + aux->rra;
		aux->moves = aux->moves + aux->rrb;
		aux->moves = aux->moves + aux->rrr;
		if (min_moves > aux->moves)
			min_moves = aux->moves;
		aux = aux->next;
	}
	return (min_moves);
}

static void	ft_copy_moves(int moves, t_control *control)
{
	t_list	*aux;

	aux = control->stack_a;
	while (moves != aux->moves)
		aux = aux->next;
	control->ra = aux->ra;
	control->rb = aux->rb;
	control->rr = aux->rr;
	control->rra = aux->rra;
	control->rrb = aux->rrb;
	control->rrr = aux->rrr;
}

static void	ft_do_moves(t_control *control)
{
	while (control->ra--)
		ft_rotate(control, 'a');
	while (control->rb--)
		ft_rotate(control, 'b');
	while (control->rr--)
		ft_rotate(control, 'r');
	while (control->rra--)
		ft_rrotate(control, 'a');
	while (control->rrb--)
		ft_rrotate(control, 'b');
	while (control->rrr--)
		ft_rrotate(control, 'r');
}

void	ft_push_back(t_control	*control)
{
	t_list	*aux;

	aux = control->stack_b;
	while (aux->index != control->b_size)
	{
		aux = aux->next;
		control->rb++;
	}
	if (control->rb > (control->b_size / 2))
	{
		control->rb = 0;
		while (aux)
		{
			aux = aux->next;
			control->rrb++;
		}
	}
	ft_do_moves(control);
	while (control->b_size)
		ft_push(control, 'a');
}

void	ft_ord_any(t_control *control)
{
	t_list	*aux;
	int		min_moves;

	aux = control->stack_a;
	ft_push(control, 'b');
	ft_push(control, 'b');
	while (control->a_size)
	{
		ft_count_a_moves(control);
		ft_count_b_moves(control);
		ft_optimize_moves(control->stack_a);
		min_moves = ft_total_moves(control->stack_a);
		ft_copy_moves(min_moves, control);
		ft_do_moves(control);
		ft_init_stack(1, control->stack_a);
		ft_push(control, 'b');
	}
	ft_init_values(1, control);
	ft_push_back(control);
}
