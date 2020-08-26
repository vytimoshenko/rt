/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/10 05:16:57 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	just_output(char **tmp, char **line, char **fd_arr)
{
	if (!(*line = ft_strdup(*tmp)))
		return (-1);
	ft_strdel(tmp);
	if (ft_strlen(*line) > 0)
		return (1);
	ft_strdel(fd_arr);
	return (0);
}

static	int	output_save(char **tmp, char **line, char **fd_arr)
{
	int		eol;
	int		len;

	eol = 0;
	len = 0;
	if (!tmp)
		return (-1);
	eol = ft_find_eol(*tmp);
	len = ft_strlen(*tmp);
	if (!(*line = ft_strsub(*tmp, 0, eol)))
		return (-1);
	if (!(*fd_arr = ft_strsub(*tmp, eol + 1, len - eol - 1)))
		return (-1);
	ft_strdel(tmp);
	return (1);
}

static	int	stupid(char **tmp, char **line, char **fd_arr)
{
	return (ft_find_eol(*tmp) != -1 ?
	output_save(tmp, line, fd_arr) : (just_output(tmp, line, fd_arr)));
}

static	int	read_join(char **tmp, int fd, char **line, char **fd_arr)
{
	char	buff[BUFF_SIZE + 1];
	char	*j;
	int		ret;
	int		eol;

	eol = -1;
	while (eol == -1)
	{
		if (!(ret = read(fd, buff, BUFF_SIZE)) && !(*tmp))
			return (0);
		if (!ret && *tmp)
			return (stupid(tmp, line, fd_arr));
		buff[ret] = '\0';
		if (ret && !(*tmp))
		{
			if (!(*tmp = ft_strdup(buff)))
				return (-1);
			continue ;
		}
		j = ft_strjoin(*tmp, buff);
		ft_strdel(tmp);
		*tmp = j;
		eol = ft_find_eol(*tmp);
	}
	return (output_save(tmp, line, fd_arr));
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_arr[ARR_SIZE];
	char		*tmp;

	if (fd < 0 || fd >= 8192 || !line || BUFF_SIZE < 1 ||
	BUFF_SIZE > (8184 * 1024) || read(fd, NULL, 0) == -1)
		return (-1);
	tmp = NULL;
	if (fd_arr[fd])
	{
		if (!(tmp = ft_strdup(fd_arr[fd])))
			return (-1);
		ft_strdel(&fd_arr[fd]);
	}
	if (tmp && ft_find_eol(tmp) != -1)
		return (output_save(&tmp, line, &fd_arr[fd]));
	else
		return (read_join(&tmp, fd, line, &fd_arr[fd]));
}
