/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:02:11 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 13:17:13 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_error(t_control *control)
{
	if (control->error == 1)
	{
		ft_free_lst(&control->stack_a);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (control->error == 2)
	{
		ft_free_lst(&control->stack_a);
		exit(0);
	}
	if (control->error == 3)
		exit(0);
}

void	ft_check_dupl(t_control *control)
{
	t_list	*aux;
	t_list	*stack;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = control->stack_a;
	stack = control->stack_a;
	while (stack)
	{
		aux = stack;
		j = i;
		while (aux)
		{
			if (aux->content == stack->content && i != j)
			{
				control->error = 1;
			}
			aux = aux->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}

void	ft_check_order(t_control *control)
{
	int		i;
	t_list	*stack;

	i = 0;
	stack = control->stack_a;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			i++;
		stack = stack->next;
	}
	if (i == 0 && control->error == 0)
		control->error = 2;
}
