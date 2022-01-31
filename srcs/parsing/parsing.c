/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:40:15 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/31 18:47:45 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	how_many_lines(char **av)
{
	int		nb;
	int		fd;
	char	*s;

	nb = 0;
	fd = open(av[1], O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		nb++;
		free(s);
		s = get_next_line(fd);
	}
	if (s)
		free(s);
	close(fd);
	return (nb);
}

char	**create_map(char **av)
{
	int		fd;
	int		i;
	int		nb;
	char	**map;

	i = 0;
	nb = how_many_lines(av) + 1;
	if (nb < 4)
		ft_error();
	map = malloc(sizeof(char *) * nb);
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	map[nb] = 0;
	return (map);
}

void	check_map(char **map)
{
	int	i;

	i = 1;
	if (!check_for_invalid_len(map))
		i = 0;
	if (!check_for_content(map))
		i = 0;
	if (!check_border(map))
		i = 0;
	if (!i)
		ft_error();
}

int	check_for_invalid_len(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[++i])
		if (len != (int)ft_strlen(map[i]))
			return (0);
	return (1);
}

int	check_for_content(char **map)
{
	int		i;
	int		c;
	int		e;
	int		p;
	int		j;
	char	*s;

	i = -1;
	c = 0;
	p = 0;
	e = 0;
	while (map[++i])
	{
		j = -1;
		s = map[i];
		while (s[++j])
		{
			if (s[j] == 'C')
				c = 1;
			if (s[j] == 'E')
				e = 1;
			if (s[j] == 'P')
				p = 1;
		}
	}
	if (e == 0 || c == 0 || p == 0)
		return (0);
	return (1);
}