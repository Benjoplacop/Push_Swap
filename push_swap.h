/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:58:10 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/23 12:26:43 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct s_pills
{
	int				value;
	int				index;
	struct s_pills	*next;
}			t_pills;

int		ft_test_no_letter(char **str);
void	free_tab(char **tab);
void	first_nbr_b(t_pills *stack_a, t_pills *stack_b);
int		is_empty(t_pills *stack);
void	init_stack(t_pills **s);
void	free_stack(t_pills **stack);
void	error_exit(t_pills **stack_a, t_pills **stack_b);
t_pills	*fill_stack(int len, char **argv, int *tab);
t_pills	*get_bot_stack(t_pills *stack);
t_pills	*get_second_bot_stack(t_pills *stack);
t_pills	*new_stack(int value, int *tab);
void	add_bot_stack(t_pills **stack, t_pills *new);
int		stack_size(t_pills *stack);
void	swap(t_pills *stack, char symb);
void	push(t_pills **src, t_pills **dest, char symb);
void	rotate(t_pills **stack, char symb);
void	reverse(t_pills **stack, char symb);
void	three_stack(t_pills *stack_a);
void	four_stack(t_pills *stack_a, t_pills *stack_b);
void	five_stack(t_pills *stack_a, t_pills *stack_b);
int		binary_max(int len);
t_pills	*binary(int max, t_pills *a, t_pills *b, int len);
void	ft_sort_big_stack(int len, char **av);
void	ft_sort_small_stack(int len, char **argv);
int		*croiss(int *tab, int len);
int		*class_nbr(char **av, int len);

#endif
