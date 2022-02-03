/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:57:39 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/03 20:15:31 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "../libx/mlx.h"

# define WALL "./srcs/imgs/wall.xpm"
# define FLOOR "./srcs/imgs/floor.xpm"
# define EXIT "./srcs/imgs/exit.xpm"
# define CHEST "./srcs/imgs/chest.xpm"
# define PLAYER_R "./srcs/imgs/player_r.xpm"
# define PLAYER_L "./srcs/imgs/player_l.xpm"
# define PLAYER_D "./srcs/imgs/player_d.xpm"
# define PLAYER_U "./srcs/imgs/player_u.xpm"

# define ESC 0xff1b
# define UP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int	x;
	int	y;
}	t_mlx;

/* ********** Parsing ********** */

char	**create_map(char **av);
int	how_many_lines(char **av);

void	check_map(char **map);
int	check_for_invalid_len(char **map);
int	check_border(char **map);
int	check_for_content(char **map);
int	check_for_invalid(char **map);


/* ********** Tools ********** */

void	free_char_tab(char **strs);
void	ft_error(void);
int	check_extension(char *s);

/* ********** window ********** */

int	window_height(char **map);
int	window_width(char **map);
void	*put_tiles(char c, void *mlx);
void	create_tiles(char **map, t_mlx *mlx);

#endif
