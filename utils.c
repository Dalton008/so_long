/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:19:16 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:55:01 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	map_w(t_va *va)
{
	int	len;
	int	h;

	len = 0;
	h = 0;
	while (va->mas[h][len])
	{
		if (va->mas[h][len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

int	map_h(char **str)
{
	int	h;
	int	w;

	h = 0;
	while (str[h])
	{
		w = 0;
		while (str[h][w])
			w++;
		h++;
	}
	return (h);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned long	n;

	n = 0;
	while (str1[n] != 0 || str2[n] != 0)
	{
		if (str1[n] != str2[n])
			return ((unsigned char)str1[n] - (unsigned char)str2[n]);
		n++;
	}
	return (0);
}

char	ft_strchr_check(const char *str, char ch)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if (str[n] == ch)
			return (1);
		n++;
	}
	return (0);
}

int	give_memory(t_va *va)
{
	va->img_p = (struct s_data *)malloc(sizeof(t_data));
	if (va->img_p == 0)
		return (0);
	va->walls = (struct s_data *)malloc(sizeof(t_data));
	if (va->walls == 0)
		return (0);
	va->floor = (struct s_data *)malloc(sizeof(t_data));
	if (va->floor == 0)
		return (0);
	va->door = (struct s_data *)malloc(sizeof(t_data));
	if (va->door == 0)
		return (0);
	va->coin = (struct s_data *)malloc(sizeof(t_data));
	if (va->coin == 0)
		return (0);
	va->enemy = (struct s_data *)malloc(sizeof(t_data));
	if (va->enemy == 0)
		return (0);
	return (1);
}
