/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:11:44 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/21 11:11:33 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_pills	*three_stack_help(t_pills *stack_a)
{
	int	x;
	int	y;
	int	z;

	x = stack_a->value;
	y = stack_a->next->value;
	z = stack_a->next->next->value;
	if (x > y && x < z)
		swap(stack_a, 'A');
	else if (x > y && y > z)
	{
		swap(stack_a, 'A');
		reverse(&stack_a, 'A');
	}
	else if (x > y && z > y && x > z)
		rotate(&stack_a, 'A');
	else if (y > x && z < y && z > x)
	{
		swap(stack_a, 'A');
		rotate(&stack_a, 'A');
	}
	else if (x > z && y > z && y > x)
		reverse(&stack_a, 'A');
	return (stack_a);
}

void	three_stack(t_pills *stack_a)
{
	int	x;
	int	y;
	int	z;

	x = stack_a->value;
	y = stack_a->next->value;
	z = stack_a->next->next->value;
	if (x > y && x < z)
		swap(stack_a, 'A');
	else if (x > y && y > z)
	{
		swap(stack_a, 'A');
		reverse(&stack_a, 'A');
	}
	else if (x > y && z > y && x > z)
		rotate(&stack_a, 'A');
	else if (y > x && z < y && z > x)
	{
		swap(stack_a, 'A');
		rotate(&stack_a, 'A');
	}
	else if (x > z && y > z && y > x)
		reverse(&stack_a, 'A');
	free_stack(&stack_a);
	return ;
}

void	five_stack(t_pills *stack_a, t_pills *stack_b)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (stack_a->index == 1 || stack_a->index == 0)
			push(&stack_a, &stack_b, 'B');
		else
			rotate(&stack_a, 'A');
		i++;
	}
	if (stack_b->value < stack_b->next->value)
		rotate(&stack_b, 'B');
	stack_a = three_stack_help(stack_a);
	push(&stack_b, &stack_a, 'A');
	push(&stack_b, &stack_a, 'A');
	free_stack(&stack_a);
}

void	four_stack(t_pills *stack_a, t_pills *stack_b)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (stack_a->index == 0)
		{	
			push(&stack_a, &stack_b, 'B');
			break ;
		}
		else
			rotate(&stack_a, 'A');
		i++;
	}
	stack_a = three_stack_help(stack_a);
	push(&stack_b, &stack_a, 'A');
	free_stack(&stack_a);
}

void	ft_sort_small_stack(int len, char **argv)
{
	t_pills	*stack_a;
	t_pills	*stack_b;
	int		*tab;

	stack_b = NULL;
	tab = class_nbr(argv, len);
	stack_a = fill_stack(len, argv, tab);
	if (len == 3)
		three_stack(stack_a);
	else if (len == 5)
		five_stack(stack_a, stack_b);
	else if (len == 4)
		four_stack(stack_a, stack_b);
	else if (stack_a->value > stack_a->next->value)
	{	
		swap(stack_a, 'A');
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	free(tab);
	free_tab(argv);
}
