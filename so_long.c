/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:04:41 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 12:26:14 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_m	*m;
	
	if (ac != 2)
		return (0);
	m = malloc(sizeof(t_m) * 1);
	if (!m)
		return (0);
	m->map = create_map(av);
	if (!m->map)
		return (0);
	m->mlx = mlx(init);
	m->win = mlx_new_window(m->mlx, w_width(m), w_height(m), "so_long");
	sprites_init(m);
	map_init(m->map, m);
	mlx_hook(m->win, 17, 0, close_win, m);
	mlx_hook(m->win, 2, 1L << 0, move, m);
	mlx_loop(m->mlx);
}
