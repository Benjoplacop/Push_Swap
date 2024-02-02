/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:46:35 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/18 13:22:18 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	swap(t_pills *stack)
{
	int	tmp;

	if (stack->next == NULL || stack == NULL)
	{	
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	push(t_pills **src, t_pills **dest)
{
	t_pills	*tmp;

	if (*src == NULL)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	rotate(t_pills **stack)
{
	t_pills	*tmp;
	t_pills	*last;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	last = get_bot_stack(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	reverse(t_pills **stack)
{
	t_pills	*last;
	t_pills	*tmp;
	t_pills	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	last = get_bot_stack(*stack);
	tmp2 = get_second_bot_stack(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	tmp2->next = NULL;
}

void	double_swap(t_pills *stack_a, t_pills *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
