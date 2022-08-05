/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:02:11 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/05 09:25:20 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_error(t_control *control)
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

static void	ft_check_dupl(t_control *control)
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

int	ft_check_order(int mode, t_control *control)
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
	if (mode == 0 && i == 0 && control->error == 0)
		control->error = 2;
	if (mode == 1 && i == 0)
		return (0);
	return (1);
}

void	ft_checks(t_control *control)
{
	int		i;

	if (control->error == 0)
	{
		i = ft_lstsize(control->stack_a);
		if (i == 0)
			control->error = 3;
		else if (i > 0)
		{
			ft_check_dupl(control);
			ft_check_order(0, control);
		}
	}
	ft_check_error(control);
}
