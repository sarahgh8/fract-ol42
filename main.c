#include "fractol.h"

int main ()
{
    t_base base;
    // t_displaysettings settings = {200.0, 0.0, 0.0};

    base.mlx = mlx_init();
    if(!base.mlx)
        return 0;    
    base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "Fract-ol");
    if(!base.win)
        destroy(&base);
    
    draw_mandelbrot(base.mlx, base.win);
    mlx_key_hook(base.win, key_events, &base);
    mlx_hook(base.win, 17, 0, destroy, &base);
    mlx_loop(base.mlx);

    
    return 0;
}