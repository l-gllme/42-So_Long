/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/02 18:08:38 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*put_img(char c, void *mlx)
{
	char	*relative_path = "./srcs/imgs/wall.xpm";
	char	*relative_path2 = "./srcs/imgs/white_floor.xpm";
	char	*other = "./srcs/imgs/wall2.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	if (c == '1')
		img = mlx_xpm_file_to_image(mlx, other, &img_width, &img_height);
	else if (c == '0')
		img = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	else 
		img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	return (img);
}


int	main(int ac, char **av)
{
	char	**map;
	int		i;
	int		j;
	char	*s;
	void	*mlx;
	void	*win;
	void	*img;

	if (ac != 2)
		return (0);
	if (!check_extension(av[1]))
		ft_error();
	map = create_map(av);
	if (!map)
		return (0);
	check_map(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, window_width(map), window_height(map), "So_long");
	i = -1;
	while (map[++i])
	{
		j = -1;
		s = map[i];
		while (s[++j])
		{
			if (s[j] != '\n')
			{
				img = put_img(s[j], mlx);
				mlx_put_image_to_window(mlx, win, img, j * 32, i * 32);
			}
		}
	}
	mlx_loop(mlx);
	free_char_tab(map);
	return (0);
}
