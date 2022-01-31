/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:02:21 by lguillau          #+#    #+#             */
/*   Updated: 2022/01/31 15:52:49 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int	i;

	if (ac != 2)
		return (0);
	map = create_map(av);
	if (!map)
		return (0);
	i = -1;
	/*while (map[++i])
		printf("%s\n", map[i]);*/
	return (0);
}
