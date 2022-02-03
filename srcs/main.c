/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/03 18:28:47 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(void)
{
	printf("toto\n");
	return (0);
}

int	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}
int	action(int keycode, t_mlx *mlx)
{

	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}


void	*put_img(char c, void *mlx)
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


int	main(int ac, char **av)
{
	char	**map;
	int		i;
	int		j;
	char	*s;
	t_mlx	*mlx;

	if (ac != 2)
		return (0);
	if (!check_extension(av[1]))
		ft_error();
	map = create_map(av);
	if (!map)
		return (0);
	check_map(map);
	mlx = malloc(sizeof(t_mlx) * 1);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, window_width(map), window_height(map), "So_long");
	i = -1;
	while (map[++i])
	{
		j = 0;
		s = map[i];
		while (s[j])
		{
			if (s[j] != '\n')
			{
				mlx->img = put_img(s[j], mlx->mlx);
				mlx_put_image_to_window(mlx->mlx,
					       	mlx->win, mlx->img, j * 32, i * 32);
			}
			j++;
		}
	}
	mlx_hook(mlx->win, 17, 0, win_close, &mlx);
	mlx_hook(mlx->win, 2, 1L << 0, action, &mlx);
	mlx_loop(mlx->mlx);
	free_char_tab(map);
	return (0);
}
