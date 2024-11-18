#include "fractol.h"

int main ()
{
    printf("%ld\n", ft_strlen("hello"));
    t_base *base = malloc(sizeof(t_base));
    if(!base)
    {
        free(base);
        return 0;
    }
    base->mlx = mlx_init();
    if(!base->mlx)
    {
        free(base);
        return 0;
    }
    base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "Fract-ol");
    if(!base->win)
    {
        free(base);
        return 0;
    }
    draw_mandelbrot(base->mlx, base->win);
    mlx_key_hook(base->win, key_events, base);
    mlx_loop(base->mlx);
    return 0;
}