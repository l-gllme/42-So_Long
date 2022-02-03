/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/03 13:54:53 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	print("toto\n");
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
		j = -1;
		s = map[i];
		while (s[++j])
		{
			if (s[j] != '\n')
			{
				mlx->img = put_img(s[j], mlx->mlx);
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, j * 32, i * 32);
			}
		}
	}
	mlx_loop(mlx->mlx);
	mlx_key_hook(mlx->win, key_hook, &mlx);
	free_char_tab(map);
	return (0);
}
