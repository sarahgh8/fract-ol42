#include "fractol.h"
#include <stdlib.h>

int main (int argc, char **argv)
{
    if(argc != 2 && argc != 4)
    {
        ft_putstr("Invalid argument\n");
        ft_putstr("Usage: ./fractol mandelbrot\n");
        ft_putstr("Usage: ./fractol julia\n");
        return 0;
    }
    else
    {
        t_base base;

        base.x = -0.5;
        base.y = 0.0;
        base.scale = 200;
        base.iteri = 50;

        base.mlx = mlx_init();
        if(!base.mlx)
            return 0;

        
        base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "Fract-ol");
        base.img = mlx_new_image(base.mlx, WIDTH, HEIGHT);
        base.image.buffer = (int *)mlx_get_data_addr(base.img, &base.image.bits_per_pixel, &base.image.size_line, &base.image.endian);
        
        if(!base.win)
            destroy(&base);
        // base.img = mlx_new_image(base.mlx, HEIGHT, WIDTH);
        printf("%d\n", argc);
        if(ft_strcmp(argv[1],"mandelbrot")) 
        {
            mlx_loop_hook(base.mlx, draw_mandelbrot, &base);
        }
        else if (ft_strcmp(argv[1], "julia") && argc == 4)
        {
            // printf("%f   %f\n", p1, p2);
            base.p1 = atof(argv[2]);
            base.p2 = atof(argv[3]);
            // draw_julia(&base, base.p1, base.p2);
            mlx_loop_hook(base.mlx, draw_julia, &base);
        }
        else
        {
            ft_putstr("Invalid argument\n");
            ft_putstr("Usage: ./fractol mandelbrot\n");
            ft_putstr("Usage: ./fractol julia\n");
            destroy(&base);
        }
        mlx_mouse_hook(base.win, mouse_events, &base);
        mlx_hook(base.win, 2, 1L<<0, key_events, &base);
        mlx_hook(base.win, 17, 0, destroy, &base);
        mlx_loop(base.mlx);

    }

    
    return 0;
}