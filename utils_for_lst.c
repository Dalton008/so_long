/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:44:41 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/09 14:54:59 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	last = ft_lstlast(*lst);
	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
			last->next = new;
	}
}

t_lst	*ft_lstlast(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}

t_lst	*ft_lstnew(void *content)
{
	t_lst	*list;

	list = (struct s_lst *)malloc(sizeof(t_lst));
	if (list == 0)
		return (0);
	list->str = content;
	list->next = NULL;
	return (list);
}

int	ft_lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}
