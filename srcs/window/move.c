/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 18:47:21 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	monster_loop(t_m *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < 800000000)
		x++;
	x = -1;
	while (m->map[++x])
	{
		y = 0;
		while (m->map[x][y])
		{
			if (m->map[x][y] == 'M' && m->anim_status == 0)	
				mlx_put_image_to_window(m->mlx, m->win,
					m->s.a_monster, y * 32, x * 32);
			if (m->map[x][y] == 'M' && m->anim_status == 1)	
				mlx_put_image_to_window(m->mlx, m->win,
					m->s.b_monster, y * 32, x * 32);
			if (m->map[x][y] == 'M' && m->anim_status == 2)	
				mlx_put_image_to_window(m->mlx, m->win,
					m->s.monster, y * 32, x * 32);
			y++;
		}
	}
	m->anim_status += 1;
	if (m->anim_status == 3)
		m->anim_status = 0;
	return (0);
}
