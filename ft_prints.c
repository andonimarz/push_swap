/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:27:43 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/04 12:05:50 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d	->	%d,	", stack->index, stack->content);
		printf("%d ra,	%d rb,	%d rr	", stack->ra, stack->rb, stack->rr);
		printf("%d rra,	%d rrb,	%d rrr ", stack->rra, stack->rrb, stack->rrr);
		printf("Total moves -> %d\n", stack->moves);
		stack = stack->next;
	}
}

void	ft_ctrprint(t_control *control)
{
	write(1, "\n--- Stack a ---\n", 18);
	ft_lstprint(control->stack_a);
	write(1, "\n--- Stack b ---\n", 18);
	ft_lstprint(control->stack_b);
	printf("Total moves = %d\n", control->total_moves);
}
