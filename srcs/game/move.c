/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:35 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/16 00:26:39 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static	void	count_steps(t_m *m)
{
	int	i;

	i = 13;
	m->i.steps++;
	m->i.itoa_steps = ft_itoa(m->i.steps);
	if (m->i.steps > 9)
		i = 10;
	if (m->i.steps > 99)
		i = 7;
	if (m->i.steps > 999)
		i = 4;
	if (m->i.steps > 9999)
		i = 1;
	mlx_put_image_to_window(m->mlx, m->win, m->s.wall, 0, 0);
	mlx_string_put(m->mlx, m->win, i, 19, 0xFFFFFF, m->i.itoa_steps);
	free(m->i.itoa_steps);
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
		ft_kill(m, "You died!");
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
		ft_kill(m, "You died!");
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
		ft_kill(m, "You died!");
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
		ft_kill(m, "You died!");
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
