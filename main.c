#include "fractol.h"

int main (int argc, char **argv)
{
    if(argc != 2)
    {
        ft_putstr("Invalid argument\n");
        ft_putstr("Usage: ./fractol mandelbrot\n");
        ft_putstr("Usage: ./fractol julia\n");
        return 0;
    }
    else
    {
        t_base base;

        base.settings.x = -0.5;
        base.settings.y = 0.0;
        base.settings.scale = 0.005;

        base.mlx = mlx_init();
        if(!base.mlx)
            return 0;

        
        base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "Fract-ol");
        if(!base.win)
            destroy(&base);
        // base.img = mlx_new_image(base.mlx, HEIGHT, WIDTH);
    
        if(ft_strcmp(argv[1],"mandelbrot") || ft_strcmp(argv[1],"mandel") || ft_strcmp(argv[1],"Mandelbrot") || ft_strcmp(argv[1],"Mandel")) 
        {
            draw_mandelbrot(base.mlx, base.win, base.settings);
        }
        else
        {
            ft_putstr("Invalid argument\n");
            ft_putstr("Usage: ./fractol mandelbrot\n");
            ft_putstr("Usage: ./fractol julia\n");
            destroy(&base);
        }
        mlx_hook(base.win, 2, 1L<<0, key_events, &base);
        mlx_hook(base.win, 17, 0, destroy, &base);
        mlx_loop(base.mlx);

    }

    
    return 0;
}