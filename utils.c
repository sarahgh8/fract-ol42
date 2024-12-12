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
        base->y -= SHIFTING_SCALES / base->scale;
    }
    else if (keycode == 65364) // down
    {
        base->y += SHIFTING_SCALES / base->scale;
    }
    else if (keycode == 65363) // right 
    {
        base->x -= SHIFTING_SCALES / base->scale;
    }
    else if (keycode == 65361) //left
    {
        base->x += SHIFTING_SCALES / base->scale;
    }

    // draw_mandelbrot(base);

    return (0);
}

void get_coord(double *c_x, double *c_yi, t_base base)
{
    *c_x = base.x + ((*c_x - WIDTH / 2.0) / base.scale);
    *c_yi = base.y - ((*c_yi - HEIGHT / 2.0) / base.scale);
}

int mouse_events(int mousecode, int x, int y, t_base *base)
{
    double cursor_x = x;
    double cursor_y = y; 


    get_coord(&cursor_x, &cursor_y, *base);

    if (mousecode == 5) 
    {
        base->scale /= 1.1;
        base->x = cursor_x - (cursor_x - base->x) * 1.1; 
        base->y = cursor_y - (cursor_y - base->y) * 1.1;
        base->iteri /= 1.009;
        printf("number if iteration: %Lf\n", base->iteri);
    }
    else if (mousecode == 4) 
    {
        base->scale *= 1.1; 
        base->x = cursor_x - (cursor_x - base->x) / 1.1; 
        base->y = cursor_y - (cursor_y - base->y) / 1.1;
        base->iteri *= 1.009;
        printf("number if iteration: %Lf\n", base->iteri);
    }

    // draw_mandelbrot(base);

    return 0;
// void get_coord(double *c_x, double *c_yi, t_base base)
// {
//     *c_x = base.x + ((*c_x - WIDTH / 2) / base.scale);
//     *c_yi = -base.y + ((*c_yi - HEIGHT / 2) / base.scale);
// }

// int mouse_events(int mousecode, t_base *base)
// {
//     // printf("%d\n", mousecode);

//     if(mousecode == 5) // scroll down zoom out
//     {
//         base->scale *= 1.05;
//     }
//     else if (mousecode == 4) // scroll up zoom in
//     {
//         base->scale /= 1.05;
//     }
//     draw_mandelbrot(base->mlx, base->win, *base);
//     return 0;
// }
}

// int pixels_buffer(int offset, )
