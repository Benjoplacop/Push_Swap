/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:16:54 by bhennequ          #+#    #+#             */
/*   Updated: 2023/03/14 14:05:18 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../libft/libft.h"
# include "../checker.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strjoin2(char *str, char *buff);
void	*ft_calloc2(size_t nelem, size_t size);
void	ft_bzero2(void *s, size_t n);
char	*ft_strchr2(char *s, int c);
size_t	ft_strlen2(char *str);
char	*get_line(char *str);
char	*read_str(int fd, char *str);
char	*next_line(char *str);
char	*get_next_line(int fd);

#endif
