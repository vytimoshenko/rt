/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:10:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/07 03:17:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrfill(char const *s, char c, char **arr)
{
	char **arr_st;
	char *str_st;

	arr_st = arr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!(*arr = malloc(sizeof(char) * (ft_ltrcnt(s, c) + 1))))
				ft_arrdel(arr_st);
			str_st = *arr;
			while (*s && *s != c)
			{
				**arr = *s;
				(*arr)++;
				s++;
			}
			**arr = '\0';
			*arr = str_st;
			arr++;
		}
	}
}
