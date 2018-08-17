/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:28:41 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:28:42 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	put_text(t_mlx *mlx, t_room *room)
{
	char	*str;
	int		t[2];

	if (!room->start && !room->lemin)
		return ;
	if (!(str = ft_itoa(room->lemin)))
		ft_malloc_error();
	if (!room->start)
	{
		t[0] = room->x * RES_H / mlx->d / 2 + mlx->x - ft_strlen(str) * 5;
		t[1] = room->y * RES_H / mlx->d / 2 + mlx->y - 11;
		mlx_string_put(mlx->mlx, mlx->win, t[0], t[1], COLOR_WHITE, str);
	}
	else
	{
		t[0] = room->x * RES_H / mlx->d / 2 + mlx->x - 25;
		t[1] = room->y * RES_H / mlx->d / 2 + mlx->y - 11;
		mlx_string_put(mlx->mlx, mlx->win, t[0], t[1], COLOR_WHITE, "start");
	}
	free(str);
}

void	put_texts(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < mlx->lemin->rooms)
		put_text(mlx, (mlx->lemin->room)[i]);
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, COLOR_WHITE,
		"Press SPACE to proceed");
	mlx_string_put(mlx->mlx, mlx->win, 20, 40, COLOR_WHITE,
		"W, A, S, D to move");
	mlx_string_put(mlx->mlx, mlx->win, 20, 60, COLOR_WHITE,
		"'+', '-' to zoom in and out");
}

void	text_add(t_mlx *mlx, char *str)
{
	t_move	*new;
	t_move	*next;

	if (!(new = (t_move *)malloc(sizeof(t_move))))
		ft_malloc_error();
	new->line = str;
	new->next = 0;
	if (!mlx->move)
		mlx->move = new;
	else
	{
		next = mlx->move;
		while (next->next)
			next = next->next;
		next->next = new;
	}
}
