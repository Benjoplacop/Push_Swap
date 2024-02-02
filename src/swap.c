/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:06:26 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/16 14:43:17 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pills *stack, char symb)
{
	int	tmp;

	if (stack->next == NULL || stack == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	if (symb == 'A')
		ft_putstr_fd("sa\n", 1);
	else if (symb == 'B')
		ft_putstr_fd("sb\n", 1);
}

void	push(t_pills **src, t_pills **dest, char symb)
{
	t_pills	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	if (symb == 'A')
		ft_putstr_fd("pa\n", 1);
	else if (symb == 'B')
		ft_putstr_fd("pb\n", 1);
}

void	rotate(t_pills **stack, char symb)
{
	t_pills	*tmp;
	t_pills	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_bot_stack(*stack);
	tmp->next = NULL;
	last->next = tmp;
	if (symb == 'A')
		ft_putstr_fd("ra\n", 1);
	else if (symb == 'B')
		ft_putstr_fd("rb\n", 1);
}

void	reverse(t_pills **stack, char symb)
{
	t_pills	*last;
	t_pills	*tmp;
	t_pills	*tmp2;

	last = get_bot_stack(*stack);
	tmp2 = get_second_bot_stack(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	tmp2->next = NULL;
	if (symb == 'A')
		ft_putstr_fd("rra\n", 1);
	else if (symb == 'B')
		ft_putstr_fd("rrb\n", 1);
}
