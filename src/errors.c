/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:44 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:44:45 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_input_error(char *text)
{
	ft_printf("Error: %s\n", text);
	exit(0);
}

void	ft_malloc_error(void)
{
	ft_printf("Memory allocating error\n");
	exit(0);
}
