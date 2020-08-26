/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:58 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	read_scene(t_scene *scene, char *file_name)
{
	int		fd;
	int		ret;
	char	buff[READ_BUFF_SIZE + 1];
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	ret = read(fd, buff, READ_BUFF_SIZE);
	if (!ret)
		put_error_pn("scene file is empry");
	if (read(fd, buff, READ_BUFF_SIZE))
		put_error_pn("scene file is too big");
	close(fd);
	buff[ret] = '\0';
	line = NULL;
	line = delete_whitespaces(buff);
	divide_to_items(scene, line);
	free(line);
}

void	divide_to_items(t_scene *scene, char *line)
{
	int		i;
	int		items_count;
	char	**items_array;
	int		item_size;

	if ((items_count = count_items(line)) == -1)
		put_error_wrong_scene_data(line, "missing '{'");
	items_array = (char **)(ft_memalloc(sizeof(char *) * (items_count + 2)));
	i = -1;
	while (++i < items_count)
	{
		if ((item_size = ft_strindex('}', line) + 1) < 0)
			put_error_wrong_scene_data(line, "missing '}'");
		items_array[i] = (char *)(malloc(sizeof(char) * (item_size + 1)));
		ft_strncpy(items_array[i], line, item_size);
		items_array[i][item_size] = '\0';
		if ((ft_strindex('}', items_array[i]) < 0))
			put_error_wrong_scene_data(items_array[i], "missing '}'");
		while (--item_size >= 0)
			line++;
	}
	parse_each_item(scene, items_array);
}

int		count_items(char *line)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (line[i++] != '\0')
		a = line[i] == '{' ? a + 1 : a;
	if (a == 0)
		return (-1);
	return (a);
}

int		parse_each_item(t_scene *scene, char **items_array)
{
	int	i;

	i = -1;
	while (items_array[++i] != NULL)
	{
		if (count_items_by_type(scene, items_array[i]) == -1)
			return (-1);
	}
	save_quantities(scene);
	allocate_memory(scene);
	i = -1;
	while (items_array[++i] != NULL)
	{
		if (parse_item_line(scene, items_array[i]) == -1)
			return (-1);
	}
	ft_arrdel(items_array);
	free(items_array);
	return (0);
}
