/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

char	*delete_whitespaces(char *line)
{
	int		len;
	char	*clean_line;

	len = ft_strlen(line) - count_whitespaces(line);
	clean_line = ft_strnew(len);
	copy_without_whitespaces(line, clean_line);
	return (clean_line);
}

int		count_whitespaces(char *line)
{
	int i;
	int	in_quotes;

	i = 0;
	in_quotes = FALSE;
	while (*line)
	{
		if (*line == '"')
			in_quotes = in_quotes == FALSE ? TRUE : FALSE;
		if (in_quotes == FALSE)
			i += is_whitespace(*line);
		line++;
	}
	return (i);
}

int		is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f' ||
	c == ' ')
		return (1);
	return (0);
}

void	copy_without_whitespaces(char *line, char *clean_line)
{
	int	in_quotes;

	in_quotes = FALSE;
	while (*line)
	{
		if (in_quotes == FALSE)
		{
			while (is_whitespace(*line))
				line++;
		}
		if (*line == '"')
			in_quotes = in_quotes == FALSE ? TRUE : FALSE;
		*clean_line = *line;
		line++;
		clean_line++;
	}
}
