/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 19:32:38 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_up(t_m *m)
{
	get_player_pos(m);
	if (m->map[m->c.x - 1][m->c.y] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.floor,
			m->c.y * 32, (m->c.x) * 32);
		m->map[m->c.x][m->c.y] = '0';
		m->map[m->c.x - 1][m->c.y] = 'P';
		m->c.x -= 1;
	}
	else if (m->map[m->c.x - 1][m->c.y] == 'M')
		exit(1);
	else if (m->map[m->c.x - 1][m->c.y] == 'E')
		exit(1);
	else if (m->map[m->c.x - 1][m->c.y] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.o_chest,
			m->c.y * 32, (m->c.x - 1) * 32);
		m->map[m->c.x - 1][m->c.y] = '1';
	}
	mlx_put_image_to_window(m->mlx, m->win, m->s.player_u,
		m->c.y * 32, (m->c.x) * 32);
}

void	player_down(t_m *m)
{
	get_player_pos(m);
	if (m->map[m->c.x + 1][m->c.y] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.floor,
			m->c.y * 32, (m->c.x) * 32);
		m->map[m->c.x][m->c.y] = '0';
		m->map[m->c.x + 1][m->c.y] = 'P';
		m->c.x += 1;
	}
	else if (m->map[m->c.x + 1][m->c.y] == 'M')
		exit(1);
	else if (m->map[m->c.x + 1][m->c.y] == 'E')
		exit(1);
	else if (m->map[m->c.x + 1][m->c.y] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.o_chest,
			m->c.y * 32, (m->c.x + 1) * 32);
		m->map[m->c.x + 1][m->c.y] = '1';
	}
	mlx_put_image_to_window(m->mlx, m->win, m->s.player_d,
		m->c.y * 32, (m->c.x) * 32);
}

void	player_right(t_m *m)
{
	get_player_pos(m);
	if (m->map[m->c.x][m->c.y + 1] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.floor,
			m->c.y * 32, (m->c.x) * 32);
		m->map[m->c.x][m->c.y] = '0';
		m->map[m->c.x][m->c.y + 1] = 'P';
		m->c.y += 1;
	}
	else if (m->map[m->c.x][m->c.y + 1] == 'M')
		exit(1);
	else if (m->map[m->c.x][m->c.y + 1] == 'E')
		exit(1);
	else if (m->map[m->c.x][m->c.y + 1] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.o_chest,
			(m->c.y + 1) * 32, m->c.x * 32);
		m->map[m->c.x][m->c.y + 1] = '1';
	}
	mlx_put_image_to_window(m->mlx, m->win, m->s.player_r,
		m->c.y * 32, m->c.x * 32);
}

void	player_left(t_m *m)
{
	get_player_pos(m);
	if (m->map[m->c.x][m->c.y - 1] == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.floor,
			m->c.y * 32, (m->c.x) * 32);
		m->map[m->c.x][m->c.y] = '0';
		m->map[m->c.x][m->c.y - 1] = 'P';
		m->c.y -= 1;
	}
	else if (m->map[m->c.x][m->c.y - 1] == 'M')
		exit(1);
	else if (m->map[m->c.x][m->c.y - 1] == 'E')
		exit(1);
	else if (m->map[m->c.x][m->c.y - 1] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.o_chest,
			(m->c.y - 1) * 32, m->c.x * 32);
		m->map[m->c.x][m->c.y - 1] = '1';
	}
	mlx_put_image_to_window(m->mlx, m->win, m->s.player_l,
		m->c.y * 32, m->c.x * 32);
}

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
