/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:54 by bhennequ          #+#    #+#             */
/*   Updated: 2024/01/08 12:55:17 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdio.h>

int	ft_test_legit(char **argv)
{
	int			i;
	int			j;
	long long	n;
	long long	m;

	i = 0;
	if (!(ft_atoi(argv[0]) <= 2147483647
			&& ft_atoi(argv[0]) + 1 >= -2147483647))
		return (0);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			n = ft_atoi(argv[i]);
			m = ft_atoi(argv[j++]);
			if (m == n || !(n <= 2147483647 && n + 1 >= -2147483647)
				|| !(m <= 2147483647 && m + 1 >= -2147483647))
				return (0);
		}
		i++;
	}
	return (1);
}

char	**init_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = ft_calloc(argc, sizeof(char *));
		if (!tab)
			return (NULL);
		while (argv[i + 1])
		{
			tab[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}

int	check_class(char **tab)
{
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_atoi(tab[i]) > ft_atoi(tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc == 1)
		return (1);
	tab = init_tab(argc, argv);
	while (tab[i])
		i++;
	if ((ft_test_legit(tab)) == 0 || ft_test_no_letter(tab) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_tab(tab);
		return (0);
	}
	if (check_class(tab) == 1 || i == 1)
	{	
		free_tab(tab);
		return (1);
	}
	if (i < 6 && i != 1)
		ft_sort_small_stack(i, tab);
	else if (i >= 6)
		ft_sort_big_stack(i, tab);
	return (1);
rgc, argv);
   }
