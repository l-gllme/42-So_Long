/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:57:45 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/01 16:59:37 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i = -1;
	int	j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (++i < 501)
	{
		my_mlx_pixel_put(&img, i, j, 0xFFFFFFFF);
		j++;
	}
	i = 501;
	j = 0;
	while (--i > 0 )
	{
		my_mlx_pixel_put(&img, i, j, 0xFFFFFFFF);
		j++;
	}
	my_mlx_pixel_put(&img, i, j, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
