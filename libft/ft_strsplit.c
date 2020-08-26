/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:34:31 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 10:00:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char **arr;

	if (s == NULL)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1));
	if (!(arr))
		return (NULL);
	arr[ft_wrdcnt(s, c)] = NULL;
	ft_arrfill(s, c, arr);
	return (arr);
}
