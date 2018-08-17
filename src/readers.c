/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:58:10 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:58:11 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_read_rooms(t_lemin *lemin, char **line)
{
	char	flag;

	flag = 0;
	while (get_next_line(0, line) == 1 && ft_is_room(*line))
	{
		ft_push(lemin, *line);
		if (!ft_strncmp(*line, "#", 1) && ft_strncmp(*line, "##start", 8)
			&& ft_strncmp(*line, "##end", 6))
			continue ;
		if (flag)
		{
			ft_add_room(lemin, *line);
			if (flag == 1)
				set_start(lemin);
			else if (flag == 2)
				set_end(lemin);
			flag = 0;
		}
		else if (!ft_strncmp(*line, "##start", 8))
			flag = 1;
		else if (!ft_strncmp(*line, "##end", 6))
			flag = 2;
		else
			ft_add_room(lemin, *line);
	}
}

void	ft_read_links(t_lemin *lemin, char **line)
{
	if (!*line)
		return ;
	if (!ft_add_link(lemin, *line))
	{
		free(*line);
		return ;
	}
	ft_push(lemin, *line);
	while (get_next_line(0, line) == 1 && ft_strncmp(*line, "", 1))
	{
		if (!ft_add_link(lemin, *line))
		{
			free(*line);
			return ;
		}
		ft_push(lemin, *line);
	}
}

void	ft_read_count(t_lemin *lemin, char **line)
{
	long long int	lemins;
	int				q;

	while ((q = get_next_line(0, line)) == 1 && !ft_strncmp(*line, "#", 1)
		&& ft_strncmp(*line, "##start", 8) && ft_strncmp(*line, "##end", 6))
		ft_push(lemin, *line);
	if (q != 1 || !ft_strncmp(*line, "", 1) || !ft_is_int(*line))
		ft_input_error("Doesn't set number of ant's");
	lemins = ft_atol(*line);
	if (lemins < 1 || lemins > INT_MAX)
		ft_input_error("Number of ant's must be non-null positive integer");
	ft_push(lemin, *line);
	lemin->lemins = (int)lemins;
}

char	**ft_read_lemin(t_lemin *lemin)
{
	char	*line;

	ft_read_count(lemin, &line);
	ft_read_rooms(lemin, &line);
	ft_read_links(lemin, &line);
	if (!lemin->start || !lemin->end)
		ft_input_error("Missing ##start and/or ##end");
	return (0);
}
