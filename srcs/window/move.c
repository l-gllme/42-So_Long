/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/14 13:42:50 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static	void	count_steps(t_m *m)
{
	m->i.steps++;
	printf("Steps: %d\n\r", m->i.steps);
}

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
		count_steps(m);
	}
	else if (m->map[m->c.x - 1][m->c.y] == 'M')
		exit(1);
	else if (m->map[m->c.x - 1][m->c.y] == 'E')
		ft_exit(m);
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
		count_steps(m);
	}
	else if (m->map[m->c.x + 1][m->c.y] == 'M')
		exit(1);
	else if (m->map[m->c.x + 1][m->c.y] == 'E')
		ft_exit(m);
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
		count_steps(m);
	}
	else if (m->map[m->c.x][m->c.y + 1] == 'M')
		exit(1);
	else if (m->map[m->c.x][m->c.y + 1] == 'E')
		ft_exit(m);
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
		count_steps(m);
	}
	else if (m->map[m->c.x][m->c.y - 1] == 'M')
		exit(1);
	else if (m->map[m->c.x][m->c.y - 1] == 'E')
		ft_exit(m);
	else if (m->map[m->c.x][m->c.y - 1] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->s.o_chest,
			(m->c.y - 1) * 32, m->c.x * 32);
		m->map[m->c.x][m->c.y - 1] = '1';
	}
	mlx_put_image_to_window(m->mlx, m->win, m->s.player_l,
		m->c.y * 32, m->c.x * 32);
}
