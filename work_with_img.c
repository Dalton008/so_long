/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:26:43 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:56:06 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_win(void)
{
	ft_putstr_fd("Close window\n", 1);
	exit(1);
}

int	print_map(t_va *va)
{
	va->count = 0;
	if (!give_memory(va))
		exit(0);
	va->mlx = mlx_init();
	va->win = mlx_new_window(va->mlx, va->win_w * 20, va->win_h * 20, \
		"so_long");
	va->coin->count = counter_c(va, 'C');
	va->count = 0;
	va->count_wall = 1;
	set_img(va, "xpm/wall.xpm", va->walls->img, '1');
	set_img(va, "xpm/door.xpm", va->door->img, 'E');
	set_img(va, "xpm/coin1.xpm", va->coin->img, 'C');
	set_img(va, "xpm/floor.xpm", va->floor->img, '0');
	set_img(va, "xpm/player1.xpm", va->img_p->img, 'P');
	set_img(va, "xpm/enemy.xpm", va->enemy->img, 'R');
	mlx_hook(va->win, 17, 1L << 0, close_win, va);
	mlx_key_hook(va->win, key_hook, &va);
	mlx_loop_hook(va->mlx, main_loop, va);
	mlx_loop(va->mlx);
	return (1);
}

void	init_img(t_va *va)
{
	va->img_p->img = mlx_xpm_file_to_image(va->mlx, "xpm/player2.xpm", \
		&va->win_w, &va->win_h);
	va->walls->img = mlx_xpm_file_to_image(va->mlx, "xpm/wall.xpm", \
		&va->win_w, &va->win_h);
	va->coin->img = mlx_xpm_file_to_image(va->mlx, "xpm/coin1.xpm", \
		&va->win_w, &va->win_h);
	va->floor->img = mlx_xpm_file_to_image(va->mlx, "xpm/floor.xpm", \
		&va->win_w, &va->win_h);
	va->door->img = mlx_xpm_file_to_image(va->mlx, "xpm/door.xpm", \
		&va->win_w, &va->win_h);
}

void	get_image(t_va *va, int n, int i, int flag)
{
	if (flag == 1)
		mlx_put_image_to_window(va->mlx, va->win, va->img_p->img, \
			i * 20, n * 20);
	else if (flag == 2)
		mlx_put_image_to_window(va->mlx, va->win, va->walls->img, \
			i * 20, n * 20);
	else if (flag == 3)
		mlx_put_image_to_window(va->mlx, va->win, va->coin->img, \
			i * 20, n * 20);
	else if (flag == 4)
		mlx_put_image_to_window(va->mlx, va->win, va->floor->img, \
			i * 20, n * 20);
	else if (flag == 5)
		mlx_put_image_to_window(va->mlx, va->win, va->door->img, \
			i * 20, n * 20);
}

int	main_loop(t_va *va)
{
	if (va->coin->count <= 0)
		set_img(va, "xpm/dooropen.xpm", va->door->img, 'E');
	return (1);
}
