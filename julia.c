#include "fractol.h"

int is_escaping_julia(double z_x, double z_yi,t_base *base)
{
    t_vars v;
    v.i = 1;
    double real_z_temp = 0;

    while(v.i < base->iteri) // z = z^2 + c ==> (a  + bi)^2 + (x + yi)
    {
        real_z_temp = (z_x*z_x) - (z_yi*z_yi) + base->p1;
        z_yi = (2 * z_x * z_yi) + base->p2;
        z_x = real_z_temp;
        
        if((z_x*z_x)+(z_yi*z_yi) > 4)
            return v.i;
        v.i++;
    }
    return 0;
}

int draw_julia(t_base *base)
{
    t_vars v;
    t_ccomplex z;

    v.x = 0;
    v.y = 0;
    v.i = 0;
    // printf("%f   %f\n", base->p1, base->p2);
    while(v.y < HEIGHT)
    {
        while(v.x < WIDTH)
        {
            z.x = v.x;
            z.yi = v.y;
            get_coord(&z.x, &z.yi, *base);
            v.i = is_escaping_julia(z.x, z.yi, base);
            int offset = v.y * WIDTH + (v.x);

            if(v.i > 0)
                base->image.buffer[offset] = 0x0066FF * v.i;
            else
                base->image.buffer[offset] = 0x000000;
            v.x++;
        }
        v.x = 0;
        v.y++;
    }
    mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
    return 0;
}