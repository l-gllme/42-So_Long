/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:47 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/01 15:17:33 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	window_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	return (i * 64);
}

int	window_width(char **map)
{
	return ((int)ft_strlen(map[0]) * 64);
}
