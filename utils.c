#include "fractol.h"

int key_events(int keycode, t_base *base, t_keyarrows *k)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 65307)
    {
        mlx_clear_window(base->mlx, base->win);
        mlx_destroy_window(base->mlx, base->win);
        free(base);                  
        exit(0);                              
    }
    else if(keycode == 65362) // up
    {
        k->y -= 10;
    }
    else if(keycode == 65364) // down
    {
        k->y += 10;
    }
    else if(keycode == 65361) // left
    {
        k->x -= 10;
    }
    else if(keycode == 65363) // right
    {
        k->x += 10;
    }
    
    return (0);
}