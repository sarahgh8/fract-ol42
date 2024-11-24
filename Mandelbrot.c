#include "fractol.h"

int is_escaping_mandel(double c_x, double c_yi)
{
    t_vars v;
    t_zcomplex z;
    v.i = 1;
    z.x = 0;
    z.yi = 0;
    double real_z_temp = 0;

    while(v.i < 25) // z = z^2 + c ==> (a  + bi)^2 + (x + yi)
    {
        real_z_temp = (z.x*z.x) - (z.yi*z.yi) + c_x;
        z.yi = (2 * z.x * z.yi) + c_yi;
        z.x = real_z_temp;
        
        if(pow(z.x, 2)+pow(z.yi, 2) > 4)
            return v.i;
        v.i++;
    }
    return 0;
}

void draw_mandelbrot(void *mlx, void *win)
{
    t_vars v;
    t_ccomplex c;
    v.x = 0;
    v.y = 0;
    v.i = 0;
    while(v.y < HEIGHT)
    {
        while(v.x < WIDTH)
        {
            c.x = v.x - 100;
            c.yi = v.y; 
            get_coord(&c.x, &c.yi);
            if((v.i = is_escaping_mandel(c.x, c.yi)))
                mlx_pixel_put(mlx, win, v.x, v.y, 0X0000FF + v.i*10);
            else
                mlx_pixel_put(mlx, win, v.x, v.y, 000);
            v.x++;
        }
        v.x = 0;
        v.y++;
    }
}