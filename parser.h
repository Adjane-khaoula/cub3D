/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:57 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/27 18:55:59 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

typedef struct s_data
{
	int		fd;
	char	**line;
	char	**identifier;
	char	**tab_identifier;
	char	*init_map;
	char	**map;
} t_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
// char	**parse_texture(char *texture, char **identifier, char **tab_identifier);
void	parse_texture(t_data **data);
int		ft_atoi(const char	*str);
int		len_tab(char **tab_identifier);
int		ft_isnum(int c);
# endif
