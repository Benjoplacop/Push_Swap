/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:46:19 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/21 11:29:37 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	double_reverse(t_pills **stack_a, t_pills **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}

int	ft_test_arg(char *line, t_pills **stack_a, t_pills **stack_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap((*stack_a));
	else if (!ft_strncmp(line, "sb\n", 3))
		swap((*stack_b));
	else if (!ft_strncmp(line, "ss\n", 3))
		double_swap((*stack_a), (*stack_b));
	else if (!ft_strncmp(line, "pa\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		double_rotate(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse(stack_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		double_reverse(stack_a, stack_b);
	else
		return (100);
	return (1);
}

void	check_croiss(t_pills *stack_a, t_pills *stack_b)
{
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	init_check(int len, char **argv)
{
	char	*line;
	int		tmp;
	t_pills	*stack_a;
	t_pills	*stack_b;

	stack_b = NULL;
	stack_a = fill_stack(len, argv);
	tmp = 1;
	while (tmp)
	{
		line = get_next_line(0);
		if (!line)
			tmp = 0;
		else if (ft_test_arg(line, &stack_a, &stack_b) == 100)
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		free(line);
	}
	check_croiss(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_tab(argv);
}
