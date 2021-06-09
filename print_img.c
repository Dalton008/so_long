/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:44:25 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:54:57 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	pr_img(t_va *va, char *path, void *img)
{
	img = mlx_xpm_file_to_image(va->mlx, path, &va->win_w, &va->win_h);
	mlx_put_image_to_window(va->mlx, va->win, \
		img, va->x * 20, va->y * 20);
}

void	set_img(t_va *va, char *p, void *img, char ch)
{
	int	i;
	int	n;
	int	len;

	n = 0;
	while (va->mas[n])
	{
		i = 0;
		len = ft_strlen(va->mas[n]);
		while (len--)
		{
			if (va->mas[n][i] == ch)
			{
				img = mlx_xpm_file_to_image(va->mlx, p, &va->win_w, &va->win_h);
				if (ch != 'R' && ch != 'E')
				{
					va->x = i;
					va->y = n;
				}
				mlx_put_image_to_window(va->mlx, va->win, img, i * 20, n * 20);
			}
			i++;
		}
		n++;
	}
}

int	counter_c(t_va *va, char ch)
{
	int	i;
	int	n;
	int	len;
	int	count;

	n = 0;
	count = 0;
	while (va->mas[n])
	{
		i = 0;
		len = ft_strlen(va->mas[n]);
		while (len--)
		{
			if (va->mas[n][i] == ch)
				count++;
			i++;
		}
		n++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + 48), fd);
}

void	print_walls(t_va *va)
{
	ft_putstr_fd("Count walls: ", 1);
	ft_putnbr_fd(va->count_wall, 1);
	ft_putstr_fd("\n", 1);
}
