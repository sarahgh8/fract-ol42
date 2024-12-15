/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:21:29 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:31 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_escaping_mandel(double c_x, double c_yi, int iteri)
{
	t_vars		v;
	t_zcomplex	z;
	double		real_z_temp;

	v.i = 1;
	z.x = 0;
	z.yi = 0;
	real_z_temp = 0;
	while (v.i < iteri)
	{
		real_z_temp = (z.x * z.x) - (z.yi * z.yi) + c_x;
		z.yi = (2 * z.x * z.yi) + c_yi;
		z.x = real_z_temp;
		if ((z.x * z.x) + (z.yi * z.yi) > 4)
			return (v.i);
		v.i++;
	}
	return (0);
}

int	draw_mandelbrot(t_base *base)
{
	t_vars		v;
	t_ccomplex	c;
	int			offset;

	vars_init(&v);
	while (v.y < HEIGHT)
	{
		while (v.x < WIDTH)
		{
			c.x = v.x;
			c.yi = v.y;
			get_coord(&c.x, &c.yi, *base);
			v.i = is_escaping_mandel(c.x, c.yi, base->iteri);
			offset = v.y * WIDTH + (v.x);
			if (v.i > 0)
				base->image.buffer[offset] = 0XFCBE11 * base->iteri / v.i;
			else
				base->image.buffer[offset] = 0x000000;
			v.x++;
		}
		v.x = 0;
		v.y++;
	}
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	return (0);
}
