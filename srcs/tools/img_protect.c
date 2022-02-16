/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_protect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:09:17 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/16 15:23:18 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	cut_1(int fd)
{
	fd = open(A_MONSTER, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(B_MONSTER, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(PLAYER_R, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(PLAYER_L, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(PLAYER_D, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(PLAYER_U, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
}

static void	cut_2(int fd)
{
	fd = open(O_CHEST, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(MONSTER, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
}

void	check_imgs(void)
{
	int	fd;

	fd = 0;
	cut_1(fd);
	cut_2(fd);
	fd = open(WALL, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(FLOOR, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(EXIT, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
	fd = open(CHEST, 0);
	if (fd == -1)
		ft_error("Img error");
	close(fd);
}
