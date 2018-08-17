/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:23:17 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:23:18 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	draw_line_low(t_mlx *mlx)
{
	int		tab[6];

	tab[0] = mlx->line->p1->x - mlx->line->p0->x;
	tab[1] = mlx->line->p1->y - mlx->line->p0->y;
	tab[2] = 1;
	if (tab[1] < 0 && (tab[2] = -1))
		tab[1] = -tab[1];
	tab[3] = 2 * tab[1] - tab[0];
	tab[4] = mlx->line->p0->y;
	tab[5] = mlx->line->p0->x;
	while (tab[5] <= mlx->line->p1->x)
	{
		if (tab[5] > -1 && tab[5] < RES_W && tab[4] > -1 && tab[4] < RES_H)
			image_set_pixel(mlx, tab[5], tab[4], COLOR_GREEN);
		if (tab[3] > 0)
		{
			tab[4] = tab[4] + tab[2];
			tab[3] = tab[3] - 2 * tab[0];
		}
		tab[3] = tab[3] + 2 * tab[1];
		tab[5]++;
	}
}

void	draw_line_high(t_mlx *mlx)
{
	int	tab[6];

	tab[0] = mlx->line->p1->x - mlx->line->p0->x;
	tab[1] = mlx->line->p1->y - mlx->line->p0->y;
	tab[2] = 1;
	if (tab[0] < 0 && (tab[2] = -1))
		tab[0] = -tab[0];
	tab[3] = 2 * tab[0] - tab[1];
	tab[4] = mlx->line->p0->x;
	tab[5] = mlx->line->p0->y;
	while (tab[5] <= mlx->line->p1->y)
	{
		if (tab[5] > -1 && tab[5] < RES_H && tab[4] > -1 && tab[4] < RES_W)
			image_set_pixel(mlx, tab[4], tab[5], COLOR_GREEN);
		if (tab[3] > 0)
		{
			tab[4] = tab[4] + tab[2];
			tab[3] = tab[3] - 2 * tab[1];
		}
		tab[3] = tab[3] + 2 * tab[0];
		tab[5]++;
	}
}

t_mlx	*rev_line(t_mlx *mlx)
{
	t_point	*point;

	point = mlx->line->p0;
	mlx->line->p0 = mlx->line->p1;
	mlx->line->p1 = point;
	return (mlx);
}

void	draw_line(t_mlx *mlx)
{
	if (abs((int)mlx->line->p1->y - (int)mlx->line->p0->y) <
		abs((int)mlx->line->p1->x - (int)mlx->line->p0->x))
	{
		if (mlx->line->p0->x > mlx->line->p1->x)
			draw_line_low(rev_line(mlx));
		else
			draw_line_low(mlx);
	}
	else
	{
		if (mlx->line->p0->y > mlx->line->p1->y)
			draw_line_high(rev_line(mlx));
		else
			draw_line_high(mlx);
	}
}

void	draw_wires(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->lemin->rooms)
	{
		j = -1;
		while (++j < (mlx->lemin->room)[i]->links)
		{
			mlx->line->p0->x = (mlx->lemin->room)[i]->x *
			RES_H / mlx->d / 2 + mlx->x;
			mlx->line->p0->y = (mlx->lemin->room)[i]->y *
			RES_H / mlx->d / 2 + mlx->y;
			mlx->line->p1->x = ((mlx->lemin->room)[i]->link)[j]->x *
			RES_H / mlx->d / 2 + mlx->x;
			mlx->line->p1->y = ((mlx->lemin->room)[i]->link)[j]->y *
			RES_H / mlx->d / 2 + mlx->y;
			draw_line(mlx);
		}
	}
	draw_circles(mlx);
}
