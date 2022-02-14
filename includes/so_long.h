/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:57:39 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/14 13:55:20 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

#include "get_next_line.h"
#include "defines.h"
#include "../libx/mlx.h"

typedef struct	s_coord {
	int	x;
	int	y;
}	t_c;

typedef struct	s_infos {
	int	anim_status;
	int	anim_inc;
	int	rand_move;
	int	steps;
}	t_i;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	char	**map;
	t_s	s;
	t_c	c;	
	t_i	i;
}	t_m;

/* ********** Parsing ********** */

char	**create_map(char **av, t_m *m);
int	how_many_lines(char **av);

void	check_map(char **map, t_m *m);
int	check_for_invalid_len(char **map);
int	check_border(char **map);
int	check_for_content(char **map);
int	check_for_invalid(char **map);


/* ********** Tools ********** */

void	free_char_tab(char **strs);
void	ft_error(char *s);
int	check_extension(char *s);
void	get_player_pos(t_m *m);
void	ft_exit(t_m *m);
void	free_mlx(t_m *m);

/* ********** window ********** */

int	w_height(t_m *m);
int	w_width(t_m *m);
void	map_init(char **map, t_m *m);
void	struct_init(t_m *m);
int	close_window(t_m *m);
int	move(int keycode, t_m *m);
int	monster_loop(t_m *m);
int	rand_move_monster(t_m *m);

/* ********** movement ********** */

void	player_up(t_m *m);
void	player_down(t_m *m);
void	player_right(t_m *m);
void	player_left(t_m *m);

#endif
