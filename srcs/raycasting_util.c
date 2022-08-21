/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:43:36 by ejang             #+#    #+#             */
/*   Updated: 2022/08/21 21:23:40 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include <math.h>

unsigned int	ft_cal_color(char *str)
{
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	char			**str_split;

	str_split = ft_split(str, ',');
	r = ft_atoi(str_split[0]);
	g = ft_atoi(str_split[1]);
	b = ft_atoi(str_split[2]);
	color = r * pow(16, 4) + g * pow(16, 2) + b;
	free_split(str_split);
	return (color);
}