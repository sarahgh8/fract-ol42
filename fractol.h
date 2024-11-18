#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#include "Libft/libft.h"

#define WIDTH 750
#define HEIGHT 750

typedef struct s_base
{
    void *mlx;
    void *win;
    void *img;
}   t_base;

typedef struct s_ccomplex
{
    double x;
    double yi;
}   t_ccomplex;

typedef struct s_zcomplex
{
    double x;
    double yi;
}   t_zcomplex;

typedef struct s_vars
{
    int x;
    int y;
    int i;
}   t_vars;

typedef struct s_keyarrows
{
    int x;
    int y;
}   t_keyarrows;

void draw_mandelbrot(void *mlx, void *win);
int is_escaping_mandel(double x, double yi);
void get_coord(double *x, double *y);
int key_events(int keycode, t_base *base, t_keyarrows *k);

#endif