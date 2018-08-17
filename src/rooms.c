/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:05:38 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:05:39 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_chroom(char *str)
{
	char	**split;

	if (!(split = ft_strsplit(str, ' ')))
		ft_malloc_error();
	if (!ft_is_int(split[1]) || !ft_is_int(split[2])
		|| ft_strpos(split[0], '-'))
	{
		ft_strarrdel(&split);
		return (0);
	}
	ft_strarrdel(&split);
	return (1);
}

int		ft_is_room(char *str)
{
	static char	start;
	static char	end;

	if (!ft_strncmp(str, "##start", 8))
	{
		if (start)
			ft_input_error("##start already defined");
		start = 1;
		return (1);
	}
	if (!ft_strncmp(str, "##end", 6))
	{
		if (end)
			ft_input_error("##end already defined");
		end = 1;
		return (1);
	}
	if (!ft_strncmp(str, "#", 1))
		return (1);
	if (!ft_strncmp(str, "L", 1))
		ft_input_error("Room name cannot begin with 'L' letter");
	if (ft_nwords(str, ' ') != 3)
		return (0);
	return (ft_chroom(str));
}

t_room	*new_room(char *name, int x, int y)
{
	t_room	*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->name = name;
	new->x = x;
	new->y = y;
	new->links = 0;
	new->link = 0;
	new->lemin = 0;
	new->step = 0;
	new->way = 0;
	new->start = 0;
	new->end = 0;
	new->visited = 0;
	return (new);
}
