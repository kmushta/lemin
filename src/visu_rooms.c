/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:32:02 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:32:03 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		pass_move(t_mlx *mlx)
{
	t_move *next;

	if (!mlx->move)
		return (0);
	next = mlx->move;
	mlx->move = mlx->move->next;
	if (next->line)
		free(next->line);
	free(next);
	if (mlx->move)
		return (1);
	return (0);
}

void	fill_room(t_lemin *lemin, char *str)
{
	int		i;
	int		ant;
	char	*name;

	ant = ft_atoi(str);
	str = str + nb_len(ant) + 1;
	name = ft_strtrim(str);
	i = -1;
	while (++i < lemin->rooms)
	{
		if (!ft_strcmp((lemin->room)[i]->name, name))
		{
			free(name);
			(lemin->room)[i]->lemin = ant;
			return ;
		}
	}
}

void	fill_rooms(t_mlx *mlx)
{
	char	**split;
	int		i;

	if (!mlx->move)
		exit(0);
	i = -1;
	while (++i < mlx->lemin->rooms)
		(mlx->lemin->room)[i]->lemin = 0;
	split = ft_strsplit(mlx->move->line, 'L');
	i = 0;
	while (split[i])
		fill_room(mlx->lemin, split[i++]);
	ft_strarrdel(&split);
	ft_printf("%s\n", mlx->move->line);
	pass_move(mlx);
}
