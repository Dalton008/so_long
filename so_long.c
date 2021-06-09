/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:42:45 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:54:58 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**make_map(t_lst **lst, int size)
{
	t_lst	*head;
	char	**map;
	int		i;

	i = 0;
	head = *lst;
	map = (char **) malloc((size + 1) * sizeof(char *));
	if (map == 0)
		return (0);
	while (head)
	{
		map[i] = head->str;
		head = head->next;
		i++;
	}
	map[i] = 0;
	return (map);
}

int	ex(t_va **va, int y, int x)
{
	if ((*va)->mas[(*va)->y + y][(*va)->x + x] == 'C')
		(*va)->coin->count--;
	if ((*va)->mas[(*va)->y + y][(*va)->x + x] == 'E')
	{
		if ((*va)->coin->count > 0)
			pr_img(*va, "xpm/player1.xpm", (*va)->img_p->img);
		else
		{
			print_walls(*va);
			exit(1);
		}
		return (0);
	}
	else if ((*va)->mas[(*va)->y + y][(*va)->x + x] == 'R')
	{
		write(1, "You die!\n", 9);
		exit(1);
	}
	return (1);
}

void	change_pos(t_va **va, int y, int x)
{
	if (ex(va, y, x))
	{
		if ((*va)->mas[(*va)->y + y][(*va)->x + x] == '1')
			pr_img(*va, "xpm/player1.xpm", (*va)->img_p->img);
		else
		{
			print_walls(*va);
			(*va)->count++;
			(*va)->count_wall++;
			pr_img(*va, "xpm/floor.xpm", (*va)->floor->img);
			(*va)->y = (*va)->y + y;
			(*va)->x = (*va)->x + x;
			if ((*va)->count % 2 == 0)
				pr_img(*va, "xpm/player1.xpm", (*va)->img_p->img);
			else if ((*va)->count % 3 == 0)
				pr_img(*va, "xpm/player2.xpm", (*va)->img_p->img);
			else
				pr_img(*va, "xpm/player3.xpm", (*va)->img_p->img);
		}
	}
}

int	key_hook(int keycode, t_va **va)
{
	int	n;

	n = 0;
	if (keycode == 53)
	{
		print_walls(*va);
		exit(1);
	}
	if (keycode == 13)
		change_pos(va, -1, 0);
	else if (keycode == 0)
		change_pos(va, 0, -1);
	else if (keycode == 1)
		change_pos(va, 1, 0);
	else if (keycode == 2)
		change_pos(va, 0, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_lst	*lst;
	t_va	va;
	char	*map_name;

	if (argc == 2)
		map_name = argv[1];
	else
		return (0);
	lst = NULL;
	fd = open(map_name, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew(line));
	ft_lstadd_back(&lst, ft_lstnew(line));
	va.mas = make_map(&lst, ft_lstsize(lst));
	va.win_w = map_w(&va);
	va.win_h = map_h(va.mas);
	if (check_map(va.mas, &va) == -1)
	{
		ft_putstr_fd("Invalid map\n", 1);
		return (0);
	}
	print_map(&va);
}
