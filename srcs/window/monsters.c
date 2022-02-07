/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:04:48 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/07 14:51:43 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_img(t_m *m, int x, int y)
{
	if (m->map[x][y] == 'M' && m->i.anim_status == 0)	
		mlx_put_image_to_window(m->mlx, m->win,
			m->s.a_monster, y * 32, x * 32);
	if (m->map[x][y] == 'M' && m->i.anim_status == 1)	
		mlx_put_image_to_window(m->mlx, m->win,
			m->s.b_monster, y * 32, x * 32);
	if (m->map[x][y] == 'M' && m->i.anim_status == 2)	
		mlx_put_image_to_window(m->mlx, m->win,
			m->s.monster, y * 32, x * 32);
}

int	monster_loop(t_m *m)
{
	int	x;
	int	y;

	x = -1;
	if (m->i.anim_inc == 100000)
	{
		m->i.anim_inc = 0;
		while (m->map[++x])
		{
			y = 0;
			while (m->map[x][y])
			{
				change_img(m, x, y);
				y++;
			}
		}
		m->i.anim_status += 1;
		if (m->i.anim_status == 3)
			m->i.anim_status = 0;
	}
	m->i.anim_inc++;
	return (0);
}
