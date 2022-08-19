/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:54:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/19 21:47:01 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"

#include <stdio.h>

void	parse_map_size(int fd, unsigned int *map_loc, int *max_height, int *max_width)
{
	char	*line;

	line = get_next_line(fd);
	// while (1)//빈 문자열이거나 공백으로만 이어진 문자열은 패스...
	// {
	// 	line = get_next_line(fd);
	// 	split_line = ft_split(line, ' ');
	// 	if (split_line != NULL && line != NULL)
	// 		break ;
	// 	free_split(split_line);
	// 	free(line);
	// 	map_loc++;
	// }
	while (line != NULL && ft_strncmp(line, "\n", ft_strlen("\n")) == 0)
	{
		*map_loc = *map_loc + 1;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		close(fd);
		print_error("Missing map content\n");
		return ;
	}
	while (line != NULL)
	{
		*max_height = *max_height + 1;
		if (*max_width < (int)ft_strlen(line))
			*max_width = (int)ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	fill_map(char *line, int fd, t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (line != NULL)
	{
		w = 0;
		while (w < (int)ft_strlen(line))
		{
			map->map[h][w] = line[w];
			w++;
		}
		while (w < map->map_width)
		{
			map->map[h][w] = ' ';
			w++;
		}
		free(line);
		line = get_next_line(fd);
		h++;
	}
}

void	map_content(char *file_name, \
	t_map *map, unsigned int map_loc)
{
	unsigned int	i;
	int				fd;
	char			*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		print_error("File open failed\n");
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL && i != map_loc)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line == NULL)
		print_error("3. Memory allocation failed");
	fill_map(line, fd, map);
	close(fd);
}
