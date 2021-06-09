/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:42:53 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:55:03 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}				t_lst;

typedef struct s_data
{
	int		x;
	int		y;
	void	*img;
	int		count;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_va {
	int				count;
	int				count_wall;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				win_w;
	int				win_h;
	char			**mas;
	char			**players_images;
	struct s_data	*img_p;
	struct s_data	*walls;
	struct s_data	*coin;
	struct s_data	*floor;
	struct s_data	*door;
	struct s_data	*enemy;
}				t_va;

typedef struct s_ck {
	int	y;
	int	x;
	int	c;
	int	p;
	int	e;
}				t_ck;

void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew(void *content);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);
size_t	ft_strlen(const char *str);
int		check_map(char **map, t_va *va);
char	ft_strchr_check(const char *str, char ch);

int		map_w(t_va *va);
int		map_h(char **str);
int		ft_strcmp(const char *str1, const char *str2);

void	print_player(t_va *va);
int		main_loop(t_va *va);
void	init_img(t_va *va);
void	get_image(t_va *va, int n, int i, int flag);
void	print_image(t_va *va, char ch);
int		print_map(t_va *va);
int		key_hook(int keycode, t_va **va);
void	change_pos(t_va **va, int y, int x);

void	pr_img(t_va *va, char *path, void *img);
void	set_img(t_va *va, char *p, void *img, char ch);

int		counter_c(t_va *va, char ch);
int		give_memory(t_va *va);
void	print_walls(t_va *va);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif