/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:57 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/27 12:22:24 by kadjane          ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	**parse_texture(char *texture, char **identifier, char **tab_identifier);
int		ft_atoi(const char	*str);
int		len_tab(char **tab_identifier);

# endif



// NO ./path_to_the_north_texture 
// SO ./path_to_the_south_texture 
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture

//         1111111111111111111111111
//         1000000000110000000000001
//         1011000001110000000000001
//         1001000000000000000000001
// 111111111011000001110000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 1111011111111011101010010001
// 11000000110101011100000010001
// 10000000000000001100000010001
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111