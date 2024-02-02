/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:19:49 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/20 18:37:48 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	binary_max(int len)
{
	int	max;

	if (len <= 4)
		max = 3;
	else if (len <= 8)
		max = 4;
	else if (len <= 16)
		max = 5;
	else if (len <= 32)
		max = 6;
	else if (len <= 64)
		max = 7;
	else if (len <= 128)
		max = 8;
	else if (len <= 256)
		max = 9;
	else if (len <= 512)
		max = 10;
	else
		max = 11;
	return (max);
}

t_pills	*binary(int max, t_pills *a, t_pills *b, int len)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < max - 1)
	{
		i = 0;
		while (i < len)
		{
			if (((a->index >> bit) & 1) == 0)
				push(&a, &b, 'B');
			else
				rotate(&a, 'A');
			i++;
		}
		while (!is_empty(b))
			push(&b, &a, 'A');
		bit++;
	}
	return (a);
}

int	*croiss(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i <= len - 1)
	{
		j = i + 1;
		while (j <= len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*class_nbr(char **av, int len)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	tab = croiss(tab, i - 1);
	return (tab);
}

void	ft_sort_big_stack(int len, char **av)
{
	t_pills	*stack_a;
	t_pills	*stack_b;
	int		*tab;

	stack_b = NULL;
	tab = class_nbr(av, len);
	stack_a = fill_stack(len, av, tab);
	stack_a = binary(binary_max(len), stack_a, stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(tab);
	free_tab(av);
}
