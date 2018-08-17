/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:26:33 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:26:34 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	draw_circle(t_mlx *mlx, t_circle *c)
{
	int		i;
	int		j;

	i = -c->r - 1;
	while (++i <= c->r)
	{
		if (c->x + i < 0 || c->x + i >= RES_W)
			continue ;
		j = -c->r - 1;
		while (++j <= c->r)
		{
			if (c->y + j < 0 || c->y + j >= RES_H)
				continue ;
			if (abs(i * i + j * j - c->r * c->r) < c->r)
				image_set_pixel(mlx, c->x + i, c->y + j, c->c);
			else if (i * i + j * j < c->r * c->r)
				image_set_pixel(mlx, c->x + i, c->y + j, 0);
		}
	}
}

void	draw_circles(t_mlx *mlx)
{
	int			i;

	mlx->c->r = 30;
	i = -1;
	while (++i < mlx->lemin->rooms)
	{
		mlx->c->x = (mlx->lemin->room)[i]->x * RES_H / mlx->d / 2 + mlx->x;
		mlx->c->y = (mlx->lemin->room)[i]->y * RES_H / mlx->d / 2 + mlx->y;
		mlx->c->c = COLOR_GREEN;
		if ((mlx->lemin->room)[i]->start)
			mlx->c->c = COLOR_BLUE;
		else if ((mlx->lemin->room)[i]->end)
			mlx->c->c = COLOR_RED;
		draw_circle(mlx, mlx->c);
	}
}
