/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:26:06 by bhennequ          #+#    #+#             */
/*   Updated: 2023/10/11 16:16:19 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pills	*get_bot_stack(t_pills *stack)
{
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

t_pills	*new_stack(int value, int *tab)
{
	t_pills	*new;
	int		i;

	new = malloc(sizeof(t_pills));
	if (!new)
		return (NULL);
			new->value = value;
	i = 0;
	while (tab[i] != value)
		i++;
	new->index = i;
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
