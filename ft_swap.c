/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:54:15 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/19 16:34:46 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *first)
{
	int		aux;
	t_list	*second;

	second = first->next;
	aux = second->content;
	second->content = first->content;
	first->content = aux;
}

void	ft_swap()