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
    ft_printf("keycode: %d\n", keycode);
    if (keycode == 65307)
    {
        destroy(base);                             
    }
    return (0);
}
void get_coord(double *c_x, double *c_yi)
{
    *c_x -= (WIDTH / 2);
    *c_yi -= (HEIGHT / 2); 
    *c_yi *= -0.005;
    *c_x *= 0.005;
}