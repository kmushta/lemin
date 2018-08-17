/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_adds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:55 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:07:56 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_link(t_room *room, t_room *link)
{
	int		i;

	if (room == link)
		return ;
	if (!room->links)
	{
		room->link = (t_room **)malloc(sizeof(t_room));
		*(room->link) = link;
	}
	else
	{
		i = 0;
		while (i < room->links)
			if ((room->link)[i++] == link)
				return ;
		room->link = (t_room **)ft_realloc((void **)(&room->link), sizeof(t_room
			*) * room->links, sizeof(t_room *) * (room->links + 1));
		(room->link)[room->links] = link;
	}
	room->links += 1;
}

int		ft_add_link(t_lemin *lemin, char *line)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;

	if (!ft_strncmp(line, "#", 1))
		return (1);
	split = ft_strsplit(line, '-');
	if (ft_strarrlen(split) != 2)
		return (0);
	if (!(r1 = ft_select_room(lemin, *split)))
		return (0);
	if (!(r2 = ft_select_room(lemin, *(split + 1))))
		return (0);
	add_link(r1, r2);
	add_link(r2, r1);
	ft_strarrdel(&split);
	return (1);
}

void	lemin_add_room(t_lemin *lemin, char *name, int x, int y)
{
	int		i;

	if (!lemin->rooms)
	{
		if (!(lemin->room = (t_room **)ft_memalloc(sizeof(t_room *))))
			ft_malloc_error();
		(lemin->room)[0] = new_room(name, x, y);
		lemin->rooms += 1;
	}
	else
	{
		i = -1;
		while (++i < lemin->rooms)
		{
			if (!ft_strcmp((lemin->room)[i]->name, name) || ((lemin->room)[i]->x
				== x && (lemin->room)[i]->y == y))
				ft_input_error("Room already exists");
		}
		if (!(lemin->room = (t_room **)ft_realloc((void **)(&(lemin->room)),
			sizeof(t_room *) * lemin->rooms, sizeof(t_room *) * (lemin->rooms +
				1))))
			ft_malloc_error();
		(lemin->room)[lemin->rooms] = new_room(name, x, y);
		lemin->rooms += 1;
	}
}

void	ft_add_room(t_lemin *lemin, char *line)
{
	char	**split;

	if (!(split = ft_strsplit(line, ' ')))
		ft_malloc_error();
	if (ft_strarrlen(split) != 3)
		ft_input_error("Wrong room format");
	if (!ft_strlen(*split) || !ft_strncmp(*split, "#", 1) || !ft_strncmp(*split,
		"L", 1))
		ft_input_error("Bad room name");
	if (!ft_is_int(split[1]) || !ft_is_int(split[2]))
		ft_input_error("Room coordinates must be integer values only");
	lemin_add_room(lemin, *split, ft_atoi(*(split + 1)), ft_atoi(*(split + 2)));
	free(*(split + 1));
	free(*(split + 2));
	free(split);
}
