/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:18:45 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:18:46 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin	*create_lemin(void)
{
	t_lemin	*lemin;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_malloc_error();
	lemin->lemins = 0;
	lemin->current = 1;
	lemin->text = 0;
	lemin->room = 0;
	lemin->rooms = 0;
	lemin->start = 0;
	lemin->end = 0;
	if (!(lemin->way = (t_way **)malloc(sizeof(t_way *) * MAX_WAYS)))
		ft_malloc_error();
	lemin->ways = 0;
	return (lemin);
}

int		count_lem(t_lemin *lemin)
{
	int		i;
	int		j;

	i = -1;
	while (++i < lemin->ways)
		if ((lemin->way)[i]->last)
			return (1);
	i = 0;
	while (i < lemin->ways)
	{
		j = 1;
		while (j < (lemin->way)[i]->length)
		{
			if ((((lemin->way)[i])->step[j])->lemin)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	lem_shift(t_lemin *lemin, t_way *way)
{
	int		i;

	i = 0;
	while (++i < way->length)
	{
		if (i == 1)
			way->last = (way->step)[i]->lemin;
		else
			(way->step)[i - 1]->lemin = (way->step)[i]->lemin;
	}
	if (lemin->current <= lemin->lemins &&
		lemin->lemins - lemin->current >= way->min)
	{
		(way->step)[way->length - 1]->lemin = lemin->current;
		lemin->current += 1;
	}
	else
		(way->step)[way->length - 1]->lemin = 0;
}
