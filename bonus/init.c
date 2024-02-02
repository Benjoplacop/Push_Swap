/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:47:17 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/15 18:53:09 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

void	free_stack(t_pills **stack)
{
	t_pills	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error_exit(t_pills **stack_a, t_pills **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

t_pills	*fill_stack(int len, char **argv)
{
	t_pills	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < len)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			error_exit(&stack_a, NULL);
		if (i == 0)
			stack_a = new_stack(ft_atoi(argv[i]));
		else
			add_bot_stack(&stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
	return (stack_a);
}

int	is_empty(t_pills *stack)
{
	if (stack == NULL)
		return (1);
	else
		return (0);
}

void	double_rotate(t_pills **stack_a, t_pills **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
