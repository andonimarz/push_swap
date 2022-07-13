/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:48 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/13 12:17:32 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_check_int(char **argv, int i)
{
	while (argv[i])
	{
		
	}
} */

void	ft_lstprint(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

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
		aux = ft_atoi(args[i]);
		node = ft_lstnew(aux);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	char	**sp_args;
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		sp_args = ft_split(argv[1], ' ');
		//ft_check_int(sp_args, 0);
		stack_a = ft_get_stack(sp_args);
		ft_lstprint(stack_a);
	}
	else
	{
		i = 1;
		while (argv[i])
			printf("%s\n", argv[i++]);
		stack_a = ft_get_stack(&argv[1]);
	}
	//ft_check_int(argv, 0);
}
