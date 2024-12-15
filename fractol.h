/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:20:47 by sghunmin          #+#    #+#             */
/*   Updated: 2024/12/15 18:20:50 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 500
# define HEIGHT 500
# define PLUS 65451
# define MINUS 65453
# define SHIFTING_SCALES 20

typedef struct s_imgdata
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*buffer;

}				t_imgdata;

typedef struct s_base
{
	void		*mlx;
	void		*win;
	void		*img;
	long double	scale;
	long double	x;
	long double	y;
	long double	iteri;
	t_imgdata	image;
	double		p1;
	double		p2;
}				t_base;

typedef struct s_ccomplex
{
	double		x;
	double		yi;
}				t_ccomplex;

typedef struct s_zcomplex
{
	double		x;
	double		yi;
}				t_zcomplex;

typedef struct s_vars
{
	int			x;
	int			y;
	int			i;
}				t_vars;

typedef struct s_juliapa
{
	double		p1;
	double		p2;
}				t_juliapa;

int				draw_mandelbrot(t_base *base);
int				is_escaping_mandel(double x, double yi, int iteri);
void			get_coord(double *x, double *y, t_base base);
int				key_events(int keycode, t_base *base);
int				destroy(t_base *base);
int				mouse_events(int button, int x, int y, t_base *base);
int				ft_strcmp(char *arg, char *str);
void			ft_putstr(char *str);
int				draw_julia(t_base *base);
double			ft_atof(const char *str);
int				is_escaping_julia(double x, double yi, t_base *base);
void			base_init(t_base *base, char **argv);
void			vars_init(t_vars *v);
void			error_message(t_base *sbase);
#endif
