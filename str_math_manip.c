/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_math_manip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:21:38 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:40 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *arg, char *str)
{
	int	i;

	i = 0;
	while (arg[i] && str[i])
	{
		if (arg[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(char c)
{
	return (c <= 48 && c >= 57);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	divisor = 1.0;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction = fraction * 10.0 + (*str - '0');
			divisor *= 10.0;
			str++;
		}
	}
	result = result + fraction / divisor;
	return (result);
}

void	error_message(t_base *base)
{
	ft_putstr("Invalid argument\n");
	ft_putstr("Usage: ./fractol mandelbrot\n");
	ft_putstr("Usage: ./fractol julia\n");
	if (base)
		destroy(base);
}
