/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:04:41 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/14 15:37:19 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	struct_init(t_m	*m)
{
	int	i_w;
	int	i_h;

	srand(time(NULL));
	get_player_pos(m);
	m->s.floor = mlx_xpm_file_to_image(m->mlx, FLOOR, &i_w, &i_h);
	m->s.wall = mlx_xpm_file_to_image(m->mlx, WALL, &i_w, &i_h);
	m->s.player_r = mlx_xpm_file_to_image(m->mlx, PLAYER_R, &i_w, &i_h);
	m->s.player_d = mlx_xpm_file_to_image(m->mlx, PLAYER_D, &i_w, &i_h);
	m->s.player_u = mlx_xpm_file_to_image(m->mlx, PLAYER_U, &i_w, &i_h);
	m->s.player_l = mlx_xpm_file_to_image(m->mlx, PLAYER_L, &i_w, &i_h);
	m->s.chest = mlx_xpm_file_to_image(m->mlx, CHEST, &i_w, &i_h);
	m->s.o_chest = mlx_xpm_file_to_image(m->mlx, O_CHEST, &i_w, &i_h);
	m->s.exit = mlx_xpm_file_to_image(m->mlx, EXIT, &i_w, &i_h);
	m->s.monster = mlx_xpm_file_to_image(m->mlx, MONSTER, &i_w, &i_h);
	m->s.a_monster = mlx_xpm_file_to_image(m->mlx, A_MONSTER, &i_w, &i_h);
	m->s.b_monster = mlx_xpm_file_to_image(m->mlx, B_MONSTER, &i_w, &i_h);
	m->i.steps = 0;
	m->i.anim_status = 0;
	m->i.rand_move = 0;
	m->i.anim_inc = 0;
}

int	main(int ac, char **av)
{
	t_m	*m;
	
	if (ac != 2)
		ft_error("Wrong args");
	m = malloc(sizeof(t_m));
	if (!m)
		return (0);
	m->map = create_map(av, m);
	m->mlx = mlx_init();
	if (!m->mlx)
	{
		free_char_tab(m->map);
		free(m);
		ft_error("mlx error");
	}
	m->win = mlx_new_window(m->mlx, w_width(m), w_height(m), "so_long");
	struct_init(m);
	map_init(m->map, m);
	mlx_hook(m->win, 17, 0, close_window, m);
	mlx_hook(m->win, 2, 1L << 0, move, m);
	mlx_loop_hook(m->mlx, monster_loop, m);
	mlx_loop(m->mlx);
}
