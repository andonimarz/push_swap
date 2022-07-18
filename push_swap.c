/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/18 17:27:25 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------------- shittttt ------------------*/

void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

/* ---------------- end_shittttt ------------------*/

t_list	*ft_get_stack(char **args, t_control *control)
{
	int		i;
	int		aux;
	t_list	*stack;
	t_list	*node;

	i = 0;
	aux = 0;
	stack = NULL;
	while (args[i])
	{
		aux = ft_atoi_check(args[i], &control->error);
		node = ft_lstnew(aux);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
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

static void	ft_check_error(t_control *control)
{
	if (control->error == 1)
	{
		ft_free_lst(&control->stack_a);
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char		**sp_arg;
	t_control	control;

	control.stack_a = NULL;
	control.error = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		sp_arg = ft_split(argv[1], ' ');
		control.stack_a = ft_get_stack(sp_arg, &control);
		ft_free(sp_arg);
		ft_check_dupl(&control);
	}
	else
	{
		control.stack_a = ft_get_stack(&argv[1], &control);
		ft_check_dupl(&control);
	}
	ft_check_error(&control);
	ft_lstprint(control.stack_a);
	ft_free_lst(&control.stack_a);
}
