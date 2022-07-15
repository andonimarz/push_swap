/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/15 13:49:04 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------------- shittttt ------------------*/
//Crear estructura en la libreria que contenga los stacks para pasarlo 
//como parámetro a funciones posteriores. En la gestión de errores si no
//va a estar complicado liberar el split de args y el stack.
//
//Falta chequear si dos elementos son iguales. Añadirlo al atoi tuneado.

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
		ft_lstprint(stack_a);
		ft_free_lst(&stack_a);
	}
	else
	{
		stack_a = ft_get_stack(&argv[1]);
		ft_lstprint(stack_a);
		ft_free_lst(&stack_a);
	}
}
