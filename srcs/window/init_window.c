/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:47 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 12:26:08 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	w_height(t_m *m)
{
	int	i;

	i = 0;
	while (m->map[i])
		i++;
	return (i * 32);
}

int	w_width(t_m *m)
{
	return (((int)ft_strlen(m->map[0]) - 1) * 32);
}

void	*put_tiles(char c, void *mlx)
{
	int		img_width;
	int		img_height;
	void	*img;

	if (c == '1')
		img = mlx_xpm_file_to_image(mlx, WALL, &img_width, &img_height);
	else if (c == '0')
		img = mlx_xpm_file_to_image(mlx, FLOOR, &img_width, &img_height);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(mlx, EXIT, &img_width, &img_height);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(mlx, PLAYER_R, &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(mlx, CHEST, &img_width, &img_height);
	return (img);
}

void	sprites_init(t_m *m)
{
	
}

void	map_init(char **map, t_m *m)
{
	int	i;
	int	j;
	char	*s;
	void	*img;

	i = -1;
	while (map[++i])
	{
		j = -1;
		s = map[i];
		while (s[++j])
		{
			if (s[j] != '\n')
			{
				img = put_tiles(s[j], mlx->mlx);
				mlx_put_image_to_window(mlx->mlx,
					       	mlx->win, mlx->img, j * 32, i * 32);
			}
		}
	}
}
