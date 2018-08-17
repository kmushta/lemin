/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:21:09 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:21:11 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	mark_all(t_lemin *lemin)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < lemin->rooms)
	{
		j = -1;
		while (++j < lemin->rooms)
		{
			k = -1;
			while (++k < (lemin->room)[j]->links && !(lemin->room)[j]->step
				&& !(lemin->room)[j]->end)
			{
				if ((lemin->room)[j]->start)
					(lemin->room)[j]->step = INT_MAX;
				else if (((lemin->room)[j]->link)[k]->end)
					(lemin->room)[j]->step = 1;
				else if (((lemin->room)[j]->link)[k]->step > 0 &&
					((lemin->room)[j]->link)[k]->step != INT_MAX)
					(lemin->room)[j]->step =
				((lemin->room)[j]->link)[k]->step + 1;
			}
		}
	}
}

int		calculate(t_way *way, t_room *room, int a)
{
	int		i;

	if (room->end)
	{
		push_step(way, room);
		return (1);
	}
	if (!a)
		return (0);
	if (!room->start)
		push_step(way, room);
	i = 0;
	while (i < room->links)
	{
		if (!(room->link)[i]->visited && room->step >= (room->link)[i]->step)
			if (calculate(way, (room->link)[i], a - 1))
				return (1);
		i++;
	}
	if (!room->start)
		pop_step(way);
	return (0);
}

void	ft_run(t_lemin *lemin)
{
	int		min;
	int		i;
	int		j;

	mark_all(lemin);
	min = 1;
	i = -1;
	while (++i < lemin->rooms && (j = min))
	{
		(lemin->way)[i] = new_way(lemin->rooms);
		while (j < lemin->rooms)
		{
			if (calculate((lemin->way)[i], ft_select_start(lemin), j))
			{
				min = j;
				break ;
			}
			j++;
		}
		if (j == lemin->rooms)
			return ;
		lemin->ways += 1;
	}
}

void	proceed(t_lemin *lemin)
{
	t_as	*arr;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (i < lemin->ways)
		size += (lemin->way)[i++]->length;
	arr = new_as(size);
	while ((lemin->current <= lemin->lemins && lemin->current > 0)
		|| count_lem(lemin))
	{
		i = 0;
		while (i < lemin->ways)
		{
			lem_shift(lemin, (lemin->way)[i]);
			i++;
		}
		push_as(arr, lemin);
		sort_as(arr);
		print_as(arr);
	}
	del_as(&arr);
}

void	calc_n(t_lemin *lemin)
{
	int		i;

	if (lemin->ways > 1)
	{
		i = 0;
		while (++i < lemin->ways)
			(lemin->way)[i]->min =
				(lemin->way)[i]->length - (lemin->way)[0]->length;
	}
}
