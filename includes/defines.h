/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:52:31 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/15 23:12:25 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WALL "./srcs/imgs/wall.xpm"
# define FLOOR "./srcs/imgs/floor.xpm"
# define EXIT "./srcs/imgs/exit.xpm"
# define CHEST "./srcs/imgs/chest.xpm"
# define O_CHEST "./srcs/imgs/open_chest.xpm"
# define MONSTER "./srcs/imgs/monster.xpm"
# define A_MONSTER "./srcs/imgs/monster_2.xpm"
# define B_MONSTER "./srcs/imgs/monster_3.xpm"
# define PLAYER_R "./srcs/imgs/player_r.xpm"
# define PLAYER_L "./srcs/imgs/player_l.xpm"
# define PLAYER_D "./srcs/imgs/player_d.xpm"
# define PLAYER_U "./srcs/imgs/player_u.xpm"

# define ESC 0xff1b

# define W 0x77
# define A 0x61
# define S 0x73
# define D 0x64

# define UP 0xff52
# define LEFT 0xff51
# define DOWN 0xff54
# define RIGHT 0xff53

typedef struct s_sprites {
	void	*floor;
	void	*wall;
	void	*chest;
	void	*o_chest;
	void	*exit;
	void	*player_u;
	void	*player_d;
	void	*player_r;
	void	*player_l;
	void	*monster;
	void	*a_monster;
	void	*b_monster;
}	t_s;

#endif
