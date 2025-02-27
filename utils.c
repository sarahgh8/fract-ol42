/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:21:55 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:57 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_base *base)
{
	mlx_destroy_image(base->mlx, base->img);
	mlx_destroy_window(base->mlx, base->win);
	mlx_destroy_display(base->mlx);
	free(base->mlx);
	exit(0);
}

int	key_events(int keycode, t_base *base)
{
	if (keycode == 65307)
	{
		destroy(base);
	}
	else if (keycode == 65362)
	{
		base->y -= SHIFTING_SCALES / base->scale;
	}
	else if (keycode == 65364)
	{
		base->y += SHIFTING_SCALES / base->scale;
	}
	else if (keycode == 65363)
	{
		base->x -= SHIFTING_SCALES / base->scale;
	}
	else if (keycode == 65361)
	{
		base->x += SHIFTING_SCALES / base->scale;
	}
	return (0);
}

void	get_coord(double *x, double *yi, t_base base)
{
	*x = base.x + ((*x - WIDTH / 2.0) / base.scale);
	*yi = base.y - ((*yi - HEIGHT / 2.0) / base.scale);
}

int	mouse_events(int mousecode, int x, int y, t_base *base)
{
	double	cursor_x;
	double	cursor_y;

	cursor_x = x;
	cursor_y = y;
	get_coord(&cursor_x, &cursor_y, *base);
	if (mousecode == 5)
	{
		base->scale /= 1.1;
		base->x = cursor_x - (cursor_x - base->x) * 1.1;
		base->y = cursor_y - (cursor_y - base->y) * 1.1;
		base->iteri /= 1.009;
	}
	else if (mousecode == 4)
	{
		base->scale *= 1.1;
		base->x = cursor_x - (cursor_x - base->x) / 1.1;
		base->y = cursor_y - (cursor_y - base->y) / 1.1;
		base->iteri *= 1.009;
	}
	return (0);
}
