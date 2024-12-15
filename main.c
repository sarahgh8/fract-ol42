/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:21:22 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:21:23 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_base	base;

	if ((argc != 2 || ft_strcmp(argv[1], "julia")) && argc != 4) 
		error_message(NULL);
	else
	{
		base_init(&base, argv);
		if (!base.mlx)
			return (0);
		if (!base.win)
			destroy(&base);
		if (ft_strcmp(argv[1], "mandelbrot"))
			mlx_loop_hook(base.mlx, draw_mandelbrot, &base);
		else if (ft_strcmp(argv[1], "julia"))
			mlx_loop_hook(base.mlx, draw_julia, &base);
		else
			error_message(&base);
		mlx_mouse_hook(base.win, mouse_events, &base);
		mlx_hook(base.win, 2, 1L << 0, key_events, &base);
		mlx_hook(base.win, 17, 0, destroy, &base);
		mlx_loop(base.mlx);
	}
	return (0);
}
