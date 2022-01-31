/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:11:45 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/31 18:09:01 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_full_line(char *s)
{
	int	i;

	i = (int)ft_strlen(s);
	while (i != 0)
	{
		if (s[i - 1] != '1')
			return (0);
		i--;
	}
	return (1);
}

static int	check_center_line(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '1')
		return (0);
	while (s[i])
		i++;
	if (s[i - 2] != '1')
		return (0);
	return (1);
}

int	check_border(char **map)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (map[nb])
		nb++;
	nb--;
	if (!check_full_line(map[0]))
		return (0);
	if (!check_full_line(map[nb]))
		return (0);
	while (i < nb)
	{
		if (!check_center_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}
