/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:23:25 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:23:26 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_step(t_way *way, t_room *room)
{
	(way->step)[way->length] = room;
	way->length += 1;
	if (!room->end)
		room->visited = 1;
}

void	pop_step(t_way *way)
{
	if (way->length)
	{
		way->length -= 1;
		(way->step)[way->length]->visited = 0;
	}
}

void	ft_push(t_lemin *lemin, char *line)
{
	int		i;

	if (!lemin->text)
	{
		if (!(lemin->text = (char **)ft_memalloc(sizeof(char *) * 2)))
			ft_malloc_error();
		(lemin->text)[0] = line;
	}
	else
	{
		i = ft_strarrlen(lemin->text);
		if (!(lemin->text = (char **)ft_realloc((void **)(&(lemin->text)),
			sizeof(char *) * (i + 1), sizeof(char *) * (i + 2))))
			ft_malloc_error();
		(lemin->text)[i] = line;
	}
}

t_room	*ft_select_room(t_lemin *lemin, char *name)
{
	char	*rname;
	int		i;

	rname = ft_strtrim(name);
	i = 0;
	while (i < lemin->rooms)
	{
		if (!ft_strcmp((lemin->room)[i]->name, rname))
		{
			free(rname);
			return ((lemin->room)[i]);
		}
		i++;
	}
	return (0);
}

t_room	*ft_select_start(t_lemin *lemin)
{
	int		i;

	i = 0;
	while (i < lemin->rooms)
	{
		if ((lemin->room)[i]->start)
			return ((lemin->room)[i]);
		i++;
	}
	ft_input_error("No ##start found");
	return (0);
}
