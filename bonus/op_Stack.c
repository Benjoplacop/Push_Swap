/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_Stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:47:40 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/18 13:15:29 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_pills	*get_bot_stack(t_pills *stack)
{
	if (stack == NULL)
	{
		ft_putstr_fd("KO\n", 1);
		exit(0);
	}
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_pills	*get_second_bot_stack(t_pills *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_pills	*new_stack(int value)
{
	t_pills	*new;

	new = malloc(sizeof(t_pills));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_bot_stack(t_pills **stack, t_pills *new)
{
	t_pills	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_bot_stack(*stack);
	last->next = new;
}

int	stack_size(t_pills *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
