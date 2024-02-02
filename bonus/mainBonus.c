/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainBonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:42:33 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/23 15:14:51 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "checker.h"

int	ft_test_no_letter(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
			{
				if (!ft_isdigit(str[i][j + 1]))
					return (0);
			}
			else if (ft_isdigit(str[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_test_legit(char **argv)
{
	int			i;
	int			j;
	long long	n;
	long long	m;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			n = ft_atoi(argv[i]);
			m = ft_atoi(argv[j]);
			if (m == n || !(n <= 2147483647 && n - 1 >= -2147483647)
				|| !(m <= 2147483647 && n - 1 >= -2147483647))
				return (0);
			j++;
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
		while (argv[i + 1])
		{
			tab[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}

int	check_croiss_init(char **tab, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (ft_atoi(tab[i]) > ft_atoi(tab[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	tab = init_tab(argc, argv);
	while (tab[i])
		i++;
	if (!ft_test_legit(tab) || !ft_test_no_letter(tab))
	{
		free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check_croiss_init(tab, i) == 1 && i != 1)
		init_check(i, tab);
	else
		free_tab(tab);
}
