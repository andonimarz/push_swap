/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:27:43 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 12:53:38 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	ft_ctrprint(t_control *control)
{
	write(1, "\n--- Stack a ---\n", 18);
	ft_lstprint(control->stack_a);
	write(1, "\n--- Stack b ---\n", 18);
	ft_lstprint(control->stack_b);
}
