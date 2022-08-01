/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:40:35 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/01 12:18:30 by amarzana         ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_control
{
	struct s_list	*stack_a;
	int				a_size;
	int				a_moves;
	struct s_list	*stack_b;
	int				b_size;
	int				b_moves;
	int				error;
	int				index_count;
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

/*----------	ft_index	-----------*/
void	ft_index(t_control *control);

/*----------	ft_checks	-----------*/
void	ft_check_error(t_control *control);
void	ft_check_dupl(t_control *control);
int		ft_check_order(int work_type, t_control *control);

/*----------	ft_ords		-----------*/
void	ft_ord_three(t_control *control);
void	ft_ord_five(t_control *ctr);
void	ft_ord_any(t_control *control);

/*------------		moves	-----------*/
void	ft_swap(t_control *control, char c);
void	ft_rotate(t_control *control, char c);
void	ft_rrotate(t_control *control, char c);
void	ft_push(t_control *control, char c);

/*----------BORRRARARRARARARAR---------*/
void	ft_ctrprint(t_control *control);

#endif
