#include "fractol.h"

int destroy(t_base *base)
{
    mlx_destroy_window(base->mlx, base->win);
    mlx_destroy_display(base->mlx);
    free(base->mlx);                  
    exit(0);                              
}
int key_events(int keycode, t_base *base)
{
    // printf("key pressed: %d\n", keycode);
    if (keycode == 65307)
    {
        destroy(base);                             
    }
    else if (keycode == 65362) // up
    {
        base->settings.y += 10;
    }
    else if (keycode == 65364) // down
    {
        base->settings.y -= 10;
    }
    else if (keycode == 65363) // right 
    {
        base->settings.x -= 10;
    }
    else if (keycode == 65361) //left
    {
        base->settings.x += 10;
    }
    draw_mandelbrot(base->mlx, base->win, base->img, base->settings);
    return (0);
}
void get_coord(double *c_x, double *c_yi, t_displaysettings settings)
{
    *c_x += settings.x;
    *c_yi += settings.y;
    *c_x -= (WIDTH / 2);
    *c_yi -= (HEIGHT / 2); 
    *c_yi *= -0.005;
    *c_x *= 0.005;
}