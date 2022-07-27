/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 10:55:25 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ------------------ shittttt --------------------*/
//Faltan checks en las funciones de movimiento

void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	ft_ctrprint(t_control *control)
{
	write(1, "\nStack a\n", 10);
	ft_lstprint(control->stack_a);
	write(1, "\nStack b\n", 10);
	ft_lstprint(control->stack_b);
}


/* ---------------- end_shittttt ------------------*/

t_list	*ft_get_stack(char **args, t_control *control)
{
	int		i;
	int		aux;
	t_list	*stack;

	i = 0;
	aux = 0;
	stack = NULL;
	while (args[i])
	{
		aux = ft_atoi_check(args[i], &control->error);
		ft_lstadd_back(&stack, ft_lstnew(aux));
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	char		**sp_arg;
	t_control	control;

	control.stack_a = NULL;
	control.stack_b = NULL;
	control.error = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		sp_arg = ft_split(argv[1], ' ');
		control.stack_a = ft_get_stack(sp_arg, &control);
		ft_free(sp_arg);
	}
	else
		control.stack_a = ft_get_stack(&argv[1], &control);
	ft_check_dupl(&control);
	ft_check_order(&control);
	ft_check_error(&control);
	ft_ctrprint(&control);
	ft_ord_three(&control);
	ft_ctrprint(&control);
	ft_free_lst(&control.stack_a);
	ft_free_lst(&control.stack_b);
}
