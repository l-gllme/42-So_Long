/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:11:45 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/04 17:58:32 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_full_line(char *s)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(s) - 1)
	{
		if (s[i] != '1')
			return (0);
		i++;
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

int	check_for_invalid(char **map)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (map[++i])
	{
		s = map[i];
		j = -1;
		while (s[++j])
		{
			if (s[j] != '1' && s[j] != '0' && s[j] != 'C' && s[j] != 'E'
					&& s[j] != 'P' && s[j] != 'M' && s[j] != '\n')
				return (0);
		}
	}
	return (1);
}
