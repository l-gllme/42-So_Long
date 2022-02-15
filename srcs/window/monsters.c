/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:04:48 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/15 14:15:38 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_monster(t_m *m, int x, int y, int i)
{
	int	r;
	int	j;

	j = y;
	if (m->map[x][y] == 'M')	
	{
		r = rand() % 4;		
		if (r == 0)
			i += 1;		
		if (r == 1)
			i -= 1;		
		if (r == 2)
			j += 1;
		if (r == 3)
			j -= 1;
		if (m->map[i][j] != '0')
		{
			if (m->map[i][j] == 'P')
				ft_kill(m, "You died!");
			m->i.rand_move--;
			return ;
		}
		mlx_put_image_to_window(m->mlx, m->win, m->s.floor, y * 32, x * 32);
		mlx_put_image_to_window(m->mlx, m->win, m->s.monster, j * 32, i * 32);
		m->map[x][y] = '0';
		m->map[i][j] = 'M';
	}
}

int	rand_move_monster(t_m *m)
{
	int	x;
	int	y;
	int	i;

	if (m->i.rand_move == 50000)
	{
		x = -1;
		while (m->map[++x])
		{
			y = 0;
			while (m->map[x][y])
			{
				i = x;
				if (m->map[x][y] == 'M')
					move_monster(m, x, y, i);
				y++;
			}
		}

		m->i.rand_move = 0;
	}
	else
		m->i.rand_move++;
	return (0);
}

static void	change_img(t_m *m, int x, int y)
{
	int	r;

	r = rand() % 3;
	while (r == m->i.anim_status)
		r = rand() % 3;
	m->i.anim_status = r;
	if (m->map[x][y] == 'M' && m->i.anim_status == 0)	
		mlx_put_image_to_window(m->mlx, m->win, m->s.a_monster, y * 32, x * 32);
	if (m->map[x][y] == 'M' && m->i.anim_status == 1)	
		mlx_put_image_to_window(m->mlx, m->win, m->s.b_monster, y * 32, x * 32);
	if (m->map[x][y] == 'M' && m->i.anim_status == 2)	
		mlx_put_image_to_window(m->mlx, m->win, m->s.monster, y * 32, x * 32);
}

int	monster_loop(t_m *m)
{
	int	x;
	int	y;

	x = -1;
	rand_move_monster(m);
	if (m->i.anim_inc == 50000)
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
	else
		m->i.anim_inc++;
	return (0);
}
