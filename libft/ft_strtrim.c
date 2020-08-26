/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:41:10 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/22 14:31:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	finish;

	if (!(s))
		return (NULL);
	begin = 0;
	finish = ft_strlen(s) - 1;
	while (ft_sep(s[begin]))
		begin++;
	if (s[begin] == '\0')
		return (ft_strnew(1));
	while (ft_sep(s[finish]))
		finish--;
	return (ft_strsub(s, begin, finish + 1 - begin));
}
