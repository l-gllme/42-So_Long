/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 12:13:17 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
	return (0);
}
void	get_p_pos(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	char	*s;

	i = -1;
	while (map[++i])
	{
		j = -1;
		s = map[i];
		while (s[++j])
		{
			if (s[j] == 'P')
			{
				mlx->x = i;
				mlx->y = j;
				return ;
			}
		}
	}
}
int	action(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(1);
	}
	else if(keycode == UP)
	{
		get_p_pos(mlx->map, mlx);
		if (mlx->map[mlx->x - 1][mlx->y] == '0')
		{	
			mlx->map[mlx->x][mlx->y] = '0';
			mlx->map[mlx->x - 1][mlx->y] = 'P';
			create_tiles(mlx->map, mlx);
		}
	}
	else if(keycode == LEFT)
	{
		get_p_pos(mlx->map, mlx);
		if (mlx->map[mlx->x][mlx->y - 1] == '0')
		{	
			mlx->map[mlx->x][mlx->y] = '0';
			mlx->map[mlx->x][mlx->y - 1] = 'P';
			create_tiles(mlx->map, mlx);
		}
	}
	else if(keycode == RIGHT)
	{
		get_p_pos(mlx->map, mlx);
		if (mlx->map[mlx->x][mlx->y + 1] == '0')
		{	
			mlx->map[mlx->x][mlx->y] = '0';
			mlx->map[mlx->x][mlx->y + 1] = 'P';
			create_tiles(mlx->map, mlx);
		}
	}
	else if(keycode == DOWN)
	{
		get_p_pos(mlx->map, mlx);
		if (mlx->map[mlx->x + 1][mlx->y] == '0')
		{	
			mlx->map[mlx->x][mlx->y] = '0';
			mlx->map[mlx->x + 1][mlx->y] = 'P';
			create_tiles(mlx->map, mlx);
		}
	}
	return (0);
}


int	main(int ac, char **av)
{
	char	**map;
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
	mlx->map = map;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, window_width(map), window_height(map), "So_long");
	create_tiles(map, mlx);
	get_p_pos(map, mlx);
	mlx_hook(mlx->win, 17, 0, win_close, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, action, mlx);
	mlx_loop(mlx->mlx);
	free_char_tab(map);
	return (0);
}
