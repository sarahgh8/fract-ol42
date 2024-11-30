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

void draw_mandelbrot(void *mlx, void *win, void *img, t_displaysettings settings)
{
    t_vars v;
    t_ccomplex c;
    t_imgdata img_data = {0, 0, 0};

    printf("%d \n", img_data.bits_per_pixel);
    printf("%d \n", img_data.size_line);
    printf("%d \n", img_data.endian);

    char *image = mlx_get_data_addr(img, &img_data.bits_per_pixel, &img_data.size_line, &img_data.endian);
    printf("%s\n", image);

    printf("%d \n", img_data.bits_per_pixel);
    printf("%d \n", img_data.size_line);
    printf("%d \n", img_data.endian);

    v.x = 0;
    v.y = 0;
    v.i = 0;
    while(v.y < HEIGHT)
    {
        while(v.x < WIDTH)
        {
            c.x = v.x;
            c.yi = v.y;
            get_coord(&c.x, &c.yi, settings);
            if((v.i = is_escaping_mandel(c.x, c.yi)))
                mlx_pixel_put(mlx, win, v.x, v.y, 0XFCBE11 * v.i);
            else
                mlx_pixel_put(mlx, win, v.x, v.y, 000);
            v.x++;
        }
        v.x = 0;
        v.y++;
    }
}