/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:38:13 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 18:38:14 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_all(t_lemin *lemin, t_room *end)
{
	char	**text;

	text = lemin->text;
	while (*text)
		ft_printf("%s\n", *text++);
	while (lemin->current > 0 && lemin->current <= lemin->lemins)
	{
		if (lemin->current == 1)
			ft_printf("\nL%d-%s", lemin->current, end->name);
		else
			ft_printf(" L%d-%s", lemin->current, end->name);
		lemin->current += 1;
	}
	ft_printf("\n");
	exit(0);
}

void	try_oneshot(t_lemin *lemin)
{
	t_room	*start;
	int		i;

	start = ft_select_start(lemin);
	i = -1;
	while (++i < start->links)
	{
		if ((start->link)[i]->end)
			print_all(lemin, (start->link)[i]);
	}
}

int		main(int argc, char **argv)
{
	t_lemin	*lemin;
	char	**text;

	if (!argc || !argv)
		text = 0;
	lemin = create_lemin();
	ft_read_lemin(lemin);
	try_oneshot(lemin);
	ft_run(lemin);
	if (!lemin->ways)
		ft_input_error("No ways found");
	text = lemin->text;
	while (*text)
		ft_printf("%s\n", *text++);
	ways_rev(lemin);
	calc_n(lemin);
	proceed(lemin);
	ft_printf("\n");
	return (0);
}
