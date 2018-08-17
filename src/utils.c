/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:56:02 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:56:04 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_nwords(const char *s, char c)
{
	int		q;
	int		i;
	char	flag;

	flag = 0;
	q = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && !flag)
		{
			q++;
			flag = 1;
		}
		else if (*(s + i) == c && flag)
			flag = 0;
		i++;
	}
	return (q);
}

void	set_start(t_lemin *lemin)
{
	(lemin->room)[lemin->rooms - 1]->start = 1;
	lemin->start = 1;
}

void	set_end(t_lemin *lemin)
{
	(lemin->room)[lemin->rooms - 1]->end = 1;
	lemin->end = 1;
}

int		nb_len(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}
