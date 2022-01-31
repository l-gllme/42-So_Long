/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:57:39 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/31 18:37:59 by lguillau         ###   ########.fr       */
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

/* ********** Parsing ********** */

char	**create_map(char **av);
int	how_many_lines(char **av);

void	check_map(char **map);
int	check_for_invalid_len(char **map);
int	check_border(char **map);
int	check_for_content(char **map);


/* ********** Tools ********** */

void	free_char_tab(char **strs);
void	ft_error(void);
int	check_extension(char *s);

#endif
