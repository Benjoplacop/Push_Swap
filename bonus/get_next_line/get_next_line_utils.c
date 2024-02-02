/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:16:43 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/13 17:01:53 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	ft_bzero2(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n)
	{
		*p = '\0';
		p++;
		--n;
	}
}

void	*ft_calloc2(size_t nelem, size_t size)
{
	void	*tab;
	size_t	x;

	x = nelem * size;
	if (nelem == 0 || size == 0)
		return ((void *)malloc(0));
	if (x / nelem != size)
		return (NULL);
	tab = (void *)malloc(x);
	if (!tab)
		return (NULL);
	ft_bzero(tab, x);
	return (tab);
}

char	*ft_strjoin2(char *str, char *buff)
{
	char	*tab;
	size_t	i;
	size_t	j;

	tab = ft_calloc((ft_strlen(str) + ft_strlen(buff) + 1), sizeof(char));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			tab[i] = str[i];
	while (buff[j])
		tab[i++] = buff[j++];
	free(str);
	return (tab);
}
