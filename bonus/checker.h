/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:55:25 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/21 11:18:00 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct s_pills
{
	int				value;
	struct s_pills	*next;
}			t_pills;

void	free_tab(char **tab);
void	init_check(int len, char **argv);
int		ft_test_arg(char *line, t_pills **stack_a, t_pills **stack_b);
void	checker(t_pills *stack_a, t_pills *stack_b);
void	init_check(int len, char **argv);
void	free_stack(t_pills **stack);
void	error_exit(t_pills **stack_a, t_pills **stack_b);
t_pills	*fill_stack(int len, char **argv);
int		is_empty(t_pills *stack);
t_pills	*get_bot_stack(t_pills *stack);
t_pills	*get_second_bot_stack(t_pills *stack);
t_pills	*new_stack(int value);
void	add_bot_stack(t_pills **stack, t_pills *new);
int		stack_size(t_pills *stack);
void	swap(t_pills *stack);
void	push(t_pills **src, t_pills **dest);
void	rotate(t_pills **stack);
void	reverse(t_pills **stack);
char	*get_next_line(int fd);
void	double_reverse(t_pills **stack_a, t_pills **stack_b);
void	double_rotate(t_pills **stack_a, t_pills **stack_b);
void	double_swap(t_pills *stack_a, t_pills *stack_b);
void	check_croiss(t_pills *stack_a, t_pills *stack_b);

#endif
