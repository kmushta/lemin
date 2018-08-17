/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:33:20 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:33:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_mlx	*mlx_mallocs(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_malloc_error();
	if (!(mlx->line = (t_line *)malloc(sizeof(t_line))))
		ft_malloc_error();
	if (!(mlx->line->p0 = (t_point *)malloc(sizeof(t_point))))
		ft_malloc_error();
	if (!(mlx->line->p1 = (t_point *)malloc(sizeof(t_point))))
		ft_malloc_error();
	if (!(mlx->c = (t_circle *)malloc(sizeof(t_circle))))
		ft_malloc_error();
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RES_W, RES_H, "lem-in");
	mlx->img = new_image(mlx);
	mlx_key_hook(mlx->win, &key_hook, mlx);
	return (mlx);
}

t_mlx			*create_mlx(t_lemin *lemin)
{
	t_mlx	*mlx;
	int		i;

	mlx = mlx_mallocs();
	mlx->move = 0;
	mlx->lemin = lemin;
	mlx->d = 1;
	mlx->x = RES_W / 2;
	mlx->y = RES_H / 2;
	i = -1;
	while (++i < lemin->rooms)
	{
		if (abs((lemin->room)[i]->x) > mlx->d)
			mlx->d = abs((lemin->room)[i]->x);
		if (abs((lemin->room)[i]->y) > mlx->d)
			mlx->d = abs((lemin->room)[i]->y);
	}
	return (mlx);
}
