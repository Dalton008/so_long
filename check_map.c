/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:42:12 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:54:53 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_symb(char **map)
{
	char	*symb;
	int		y;
	int		x;

	y = 0;
	symb = "01ECPR";
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr_check(symb, map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	count_sprites(char **map)
{
	t_ck	ck;

	ck.x = 0;
	ck.y = 0;
	ck.e = 0;
	ck.c = 0;
	ck.p = 0;
	while (map[ck.y])
	{
		ck.x = 0;
		while (map[ck.y][ck.x])
		{
			if (map[ck.y][ck.x] == 'E')
				ck.e++;
			if (map[ck.y][ck.x] == 'P')
				ck.p++;
			if (map[ck.y][ck.x] == 'C')
				ck.c++;
			ck.x++;
		}
		ck.y++;
	}
	if ((ck.e == 0 || ck.e > 1) || (ck.p == 0 || ck.p > 1) || ck.c == 0)
		return (1);
	return (0);
}

int	check_map(char **map, t_va *va)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][0] != '1' || map[0][x] != '1')
				return (-1);
			if (map[y][va->win_w - 1] != '1')
				return (-1);
			if (map[va->win_h - 1][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	if (count_sprites(map) || check_symb(map))
		return (-1);
	return (1);
}
