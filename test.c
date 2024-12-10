#include "fractol.h"

int main (int argc, char **argv)
{
        t_base base;
        t_imgdata img;
        t_vars v;

        base.mlx = mlx_init();
        if(!base.mlx)
            return 0;

        
        base.win = mlx_new_window(base.mlx, WIDTH, HEIGHT, "Fract-ol");
        base.img = mlx_new_image(base.mlx, WIDTH, HEIGHT);
        
        int *buffer = (int *)mlx_get_data_addr(base.img, &img.bits_per_pixel, &img.size_line, &img.endian);
        v.y = 0;
        v.x = 00;
        printf("%d\n", img.size_line);
        while(v.y < HEIGHT) // 
        {
            v.x = 0;
            while(v.x < WIDTH)
            {
                if(((v.x-375)*(v.x-375)) + ((v.y-375) * (v.y-375)) <= 10000)
                {
                    int offset = v.y * WIDTH + (v.x);
                    buffer[offset] = 0XFCBE11 * v.i;
                }
                v.x++;
            }
            v.y++;

        }
        mlx_put_image_to_window(base.mlx, base.win, base.img, 0, 0);
        mlx_loop(base.mlx);

    
    return 0;
}