/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:14:34 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:14:36 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way	*new_way(int size)
{
	t_way	*new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		ft_malloc_error();
	new->length = 0;
	new->min = 0;
	new->last = 0;
	if (!(new->step = (t_room **)malloc(sizeof(t_room *) * size)))
		ft_malloc_error();
	return (new);
}

void	way_rev(t_way *way)
{
	t_room	*temp;
	int		i;
	int		j;

	i = 0;
	j = way->length - 1;
	while (i < j)
	{
		temp = (way->step)[i];
		(way->step)[i] = (way->step)[j];
		(way->step)[j] = temp;
		i++;
		j--;
	}
}

void	ways_rev(t_lemin *lemin)
{
	int		i;

	i = -1;
	while (++i < lemin->ways)
		way_rev((lemin->way)[i]);
}
