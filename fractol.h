#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#include <unistd.h>

#define WIDTH 750
#define HEIGHT 750
# define PLUS 65451
# define MINUS 65453 

typedef struct s_displaysettings
{
    double scale;
    double x;
    double y; 

}t_displaysettings;

typedef struct s_base
{
    void *mlx;
    void *win;
    void *img;
    t_displaysettings settings;

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

// typedef struct s_imgdata
// {
//     int bits_per_pixel;
// 	int size_line;
//     int endian;
// }t_imgdata;

void draw_mandelbrot(void *mlx, void *win, t_displaysettings settings);
int is_escaping_mandel(double x, double yi);
void get_coord(double *x, double *y, t_displaysettings settings);
int key_events(int keycode, t_base *base);
int destroy(t_base *base);
int mouse_events(int button, t_base *base);
int ft_strcmp(char *arg, char *str);
void ft_putstr(char *str);


#endif