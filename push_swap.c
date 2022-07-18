/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/18 16:28:45 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------------- shittttt ------------------*/
//Crear estructura en la libreria que contenga los stacks para pasarlo 
//como parámetro a funciones posteriores. En la gestión de errores si no
//va a estar complicado liberar el split de args y el stack.

void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

/* ---------------- end_shittttt ------------------*/

t_list	*ft_get_stack(char **args)
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
		aux = ft_atoi_check(args[i]);
		node = ft_lstnew(aux);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

void	ft_check_dupl(t_list *stack)
{
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = stack;
	while (stack)
	{
		aux = stack;
		j = i;
		while (aux)
		{
			if (aux->content == stack->content && i != j)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			aux = aux->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**sp_arg;
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		sp_arg = ft_split(argv[1], ' ');
		stack_a = ft_get_stack(sp_arg);
		ft_free(sp_arg);
		ft_check_dupl(stack_a);
		ft_lstprint(stack_a);
		ft_free_lst(&stack_a);
	}
	else
	{
		stack_a = ft_get_stack(&argv[1]);
		ft_check_dupl(stack_a);
		ft_lstprint(stack_a);
		ft_free_lst(&stack_a);
	}
}
