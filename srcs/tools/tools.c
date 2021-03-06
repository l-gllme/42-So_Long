/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:25:11 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/15 16:27:59 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_char_tab(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	ft_error(char *s)
{
	write(1, "Error\n", 6);
	write(1, s, (int)ft_strlen(s));
	write(1, "\n", 1);
	exit(0);
}

int	check_extension(char *s)
{
	int	i;

	i = (int)ft_strlen(s);
	if (s[i - 1] != 'r')
		return (0);
	if (s[i - 2] != 'e')
		return (0);
	if (s[i - 3] != 'b')
		return (0);
	if (s[i - 4] != '.')
		return (0);
	return (1);
}

void	get_player_pos(t_m *m)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (m->map[++i])
	{
		j = -1;
		s = m->map[i];
		while (s[++j])
		{
			if (s[j] == 'P')
			{
				m->c.x = i;
				m->c.y = j;
				return ;
			}
		}
	}
}
