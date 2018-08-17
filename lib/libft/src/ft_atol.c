/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:17:53 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:17:54 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atol(const char *str)
{
	long long unsigned int	result;
	char					sign;

	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	sign = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = 1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - 48;
	if (sign)
		return (-result);
	return (result);
}
