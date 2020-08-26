/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:01:17 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/19 20:02:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*res_str;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(res_str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		res_str[i] = f(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
