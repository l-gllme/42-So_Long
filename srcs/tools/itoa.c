/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguillau <lguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:57:15 by lguillau          #+#    #+#             */
/*   Updated: 2022/02/15 23:58:16 by lguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	put_in_tab(int *tab, int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	if (n < 0)
	{
		tab[i] = -3;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*s;
	int		tab[100];

	i = 0;
	len = put_in_tab(tab, n);
	s = malloc(sizeof(char) * (len + 3));
	if (!s)
		return (NULL);
	if (n == 0)
	{
		s[i] = '0';
		i++;
	}
	while (len > 0)
	{
		len--;
		s[i] = tab[len] + '0';
		i++;
	}
	s[i] = 0;
	return (s);
}
