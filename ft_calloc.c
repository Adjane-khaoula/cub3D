/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:36:50 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/24 22:13:59 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	char	*p;

	p = (char *)malloc(cnt * size);
	if (!p)
		return (0);
	ft_bzero(p, cnt * size);
	return (p);
}
