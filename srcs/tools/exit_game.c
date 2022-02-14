/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:44:28 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/14 15:52:15 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_sprites(t_m *m)
{
	mlx_destroy_image(m->mlx, m->s.floor);
	mlx_destroy_image(m->mlx, m->s.wall);
	mlx_destroy_image(m->mlx, m->s.chest);
	mlx_destroy_image(m->mlx, m->s.o_chest);
	mlx_destroy_image(m->mlx, m->s.exit);
	mlx_destroy_image(m->mlx, m->s.player_u);
	mlx_destroy_image(m->mlx, m->s.player_d);
	mlx_destroy_image(m->mlx, m->s.player_r);
	mlx_destroy_image(m->mlx, m->s.player_l);
	mlx_destroy_image(m->mlx, m->s.monster);
	mlx_destroy_image(m->mlx, m->s.a_monster);
	mlx_destroy_image(m->mlx, m->s.b_monster);
}

void	free_mlx(t_m *m)
{
	free_sprites(m);
	mlx_destroy_window(m->mlx, m->win);
	mlx_destroy_display(m->mlx);
	free_char_tab(m->map);
	free(m->mlx);
	free(m);
}

void	ft_exit(t_m *m)
{
	int	i;
	int	j;

	i = -1;
	while (m->map[++i])
	{
		j = -1;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'C')
			{
				write(1, "Collect all the chests !\n", 25);
				return ;
			}
		}
	}
	free_mlx(m);
	write(1, "Victory !\n", 10);
	exit(1);
}
