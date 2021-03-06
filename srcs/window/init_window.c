/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:47 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/16 00:02:33 by lguillau         ###   ########.fr       */
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

static	void	sprites_init_cut(char s, t_m *m, int i, int j)
{
	if (s == '1')
		mlx_put_image_to_window(m->mlx,
			m->win, m->s.wall, j * 32, i * 32);
	if (s == '0')
		mlx_put_image_to_window(m->mlx,
			m->win, m->s.floor, j * 32, i * 32);
	if (s == 'C')
		mlx_put_image_to_window(m->mlx,
			m->win, m->s.chest, j * 32, i * 32);
	if (s == 'E')
		mlx_put_image_to_window(m->mlx,
			m->win, m->s.exit, j * 32, i * 32);
	if (s == 'P')
		mlx_put_image_to_window(m->mlx,
			m->win, m->s.player_d, j * 32, i * 32);
}

void	map_init(char **map, t_m *m)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (map[++i])
	{
		j = -1;
		s = map[i];
		while (s[++j])
			sprites_init_cut(s[j], m, i, j);
	}
	mlx_string_put(m->mlx, m->win, 13, 19, 0xFFFFFF, "0");
}

int	move(int keycode, t_m *m)
{
	if (keycode == ESC)
		ft_kill(m, "Esc pressed");
	if (keycode == UP || keycode == W)
		player_up(m);
	if (keycode == DOWN || keycode == S)
		player_down(m);
	if (keycode == LEFT || keycode == A)
		player_left(m);
	if (keycode == RIGHT || keycode == D)
		player_right(m);
	return (0);
}
