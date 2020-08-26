/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:17:05 by mperseus          #+#    #+#             */
/*   Updated: 2019/10/05 12:02:56 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i1;
	unsigned int	i2;
	char			*res_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i1 = 0;
	while (s1[i1] != '\0')
	{
		res_str[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		res_str[i1 + i2] = s2[i2];
		i2++;
	}
	res_str[i1 + i2] = '\0';
	return (res_str);
}
