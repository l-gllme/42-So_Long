/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:40:15 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/31 15:51:38 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	how_many_lines(char **av)
{
	int		nb;
	int		fd;
	int		i;
	char	*s;

	nb = 0;
	i = 0;
	fd = open(av[1], O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		while (s[++i])
			if (s[i] == '\n')
				nb++;
		if (s)
			//free(s);
		s = get_next_line(fd);
	}
	//free(s);
	close(fd);
	return (nb + 1);
}

char	**create_map(char **av)
{
	int		fd;
	int		i;
	int		j;
	char	**map;
	char	*s;

	i = 0;
	j = -1;
	map = malloc(sizeof(char *) * (how_many_lines(av) + 1));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		map[i] = ft_strjoin(map[i], s);
		if (!map[i])
			free_char_tab(map);
		while (s[++j])
			if (s[j] == '\n')
				i++;
		//free(s);
		s = get_next_line(fd);
	}
	//free(s);
	close(fd);
	return (map);
}
