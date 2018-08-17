/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:02:18 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:02:19 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_as	*new_as(int size)
{
	t_as	*new;

	if (!(new = (t_as *)malloc(sizeof(t_as))))
		ft_malloc_error();
	new->length = size;
	if (!(new->key = (int *)malloc(sizeof(int) * size)))
		ft_malloc_error();
	if (!(new->value = (t_room **)malloc(sizeof(t_room *) * size)))
		ft_malloc_error();
	return (new);
}

void	push_as(t_as *arr, t_lemin *lemin)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < lemin->ways)
	{
		j = 0;
		while (j < (lemin->way)[i]->length)
		{
			(arr->value)[k] = ((lemin->way)[i]->step)[j];
			if (!j)
				(arr->key)[k] = (lemin->way)[i]->last;
			else
				(arr->key)[k] = ((lemin->way)[i]->step)[j]->lemin;
			k++;
			j++;
		}
		i++;
	}
}

void	sort_as(t_as *arr)
{
	t_room	*tvalue;
	int		t[4];

	t[3] = 1;
	t[1] = arr->length - 1;
	while (t[3] && t[1])
	{
		t[3] = 0;
		t[2] = 1;
		while (t[2] <= t[1])
		{
			if ((arr->key)[t[2]] < (arr->key)[t[2] - 1])
			{
				t[3] = 1;
				t[0] = (arr->key)[t[2]];
				tvalue = (arr->value)[t[2]];
				(arr->key)[t[2]] = (arr->key)[t[2] - 1];
				(arr->value)[t[2]] = (arr->value)[t[2] - 1];
				(arr->key)[t[2] - 1] = t[0];
				(arr->value)[t[2] - 1] = tvalue;
			}
			t[2]++;
		}
		t[1]--;
	}
}

void	del_as(t_as **arr)
{
	if (arr && *arr)
	{
		if ((*arr)->key)
			free((*arr)->key);
		if ((*arr)->value)
			free((*arr)->value);
		free(*arr);
	}
}

void	print_as(t_as *arr)
{
	int		i;
	char	f;

	f = 0;
	i = 0;
	while (i < arr->length)
	{
		if ((arr->key)[i])
		{
			if (f)
				ft_printf(" L%d-%s", (arr->key)[i], (arr->value)[i]->name);
			else
			{
				ft_printf("\nL%d-%s", (arr->key)[i], (arr->value)[i]->name);
				f = 1;
			}
		}
		i++;
	}
}
