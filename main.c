#include "fractol.h"

int main ()
{
    t_base base;

    base.settings.x = -100.0;
    base.settings.y = 0.0;

    base.mlx = mlx_init();
    if(!base.mlx)
        return 0;

    
    base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "Fract-ol");
    if(!base.win)
        destroy(&base);
    base.img = mlx_new_image(base.mlx, HEIGHT, WIDTH);
   

    draw_mandelbrot(base.mlx, base.win, base.img, base.settings);
    mlx_hook(base.win, 2, 1L<<0, key_events, &base);
    mlx_hook(base.win, 17, 0, destroy, &base);
    mlx_loop(base.mlx);

    
    return 0;
}