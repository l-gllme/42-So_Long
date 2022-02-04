/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:47 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 13:18:20 by lguillau         ###   ########.fr       */
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

void	map_init(char **map, t_m *m)
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
			if (s[j] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->s.wall, j * 32, i * 32);
			if (s[j] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->s.floor, j * 32, i * 32);
			if (s[j] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->s.chest, j * 32, i * 32);
			if (s[j] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->s.exit, j * 32, i * 32);
//			if (s[j] == 'M')
//				mlx_put_image_to_window(m->mlx, m->win, m->s.monster, j * 32, i * 32);
			if (s[j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->s.player_d, j * 32, i * 32);
		}
	}
}
