/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putwchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:08:34 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/25 18:08:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int			ft_printf_putwchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		return (ft_putchar(c));
	}
	if (c <= 0x7FF)
	{
		return (ft_putchar((c >> 6) + 0xC0)
			+ ft_putchar((c & 0x3F) + 0x80));
	}
	if (c <= 0xFFFF)
	{
		return (ft_putchar((c >> 12) + 0xE0)
			+ ft_putchar(((c >> 6) & 0x3F) + 0x80)
			+ ft_putchar((c & 0x3F) + 0x80));
	}
	if (c <= 0x10FFFF)
	{
		return (ft_putchar((c >> 18) + 0xF0)
			+ ft_putchar(((c >> 12) & 0x3F) + 0x80)
			+ ft_putchar(((c >> 6) & 0x3F) + 0x80)
			+ ft_putchar((c & 0x3F) + 0x80));
	}
	return (0);
}
