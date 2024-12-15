/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:21:48 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:50 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vars_init(t_vars *v)
{
	v->i = 0;
	v->x = 0;
	v->y = 0;
}

void	base_init(t_base *base, char **argv)
{
	base->x = -0.5;
	base->y = 0.0;
	base->scale = 200;
	base->iteri = 50;
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "Fract-ol");
	base->img = mlx_new_image(base->mlx, WIDTH, HEIGHT);
	base->image.buffer = (int *)mlx_get_data_addr(base->img,
			&base->image.bits_per_pixel, &base->image.size_line,
			&base->image.endian);
	if (ft_strcmp(argv[1], "julia"))
	{
		base->p1 = atof(argv[2]);
		base->p2 = atof(argv[3]);
	}
}
