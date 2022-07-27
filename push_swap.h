/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:40:35 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/27 10:22:03 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_control
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	int				error;
}					t_control;

/*-----------	utils_libft	-----------*/
char	**ft_split(char const *s, char c);
int		ft_atoi_check(const char *str, int *error);

/*-----------	utils_lst	-----------*/
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

/*-----------	utils_exit	-----------*/
void	ft_free_lst(t_list **lst);
void	ft_free(char **ptr);

/*----------	ft_checks	-----------*/
void	ft_check_error(t_control *control);
void	ft_check_dupl(t_control *control);
void	ft_check_order(t_control *control);

/*----------	ft_ords		-----------*/
void	ft_ord_three(t_control *control);

/*------------		moves	-----------*/
void	ft_swap(t_control *control, char c);
void	ft_swap_job(t_list *stack);

void	ft_rotate(t_control *control, char c);
void	ft_rotate_job(t_list *stack);

void	ft_rrotate(t_control *control, char c);

void	ft_push(t_control *control, char c);

#endif
