/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/29 11:19:15 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ------------------ shittttt --------------------*/
//Falta el algoritmo para el resto de casos
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
	control->a_size = i;
	return (stack);
}

static void	ft_checks(t_control *control)
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
			ft_check_order(control);
		}
	}
	ft_check_error(control);
}

static void	ft_push_swap(t_control *control)
{
	if (control->a_size == 3)
		ft_ord_three(control);
	else if (control->a_size == 5)
		ft_ord_five(control);
}

static void	ft_init_values(t_control *control)
{
	control->stack_a = NULL;
	control->a_size = 0;
	control->stack_b = NULL;
	control->b_size = 0;
	control->error = 0;
}

int	main(int argc, char **argv)
{
	char		**sp_arg;
	t_control	control;

	ft_init_values(&control);
	if (argc == 1)
		control.error = 3;
	else
	{
		if (argc == 2)
		{
			sp_arg = ft_split(argv[1], ' ');
			control.stack_a = ft_get_stack(sp_arg, &control);
			ft_free(sp_arg);
		}
		else
			control.stack_a = ft_get_stack(&argv[1], &control);
	}
	ft_checks(&control);
	ft_push_swap(&control);
	//ft_ctrprint(&control);
	ft_free_lst(&control.stack_a);
	ft_free_lst(&control.stack_b);
}
