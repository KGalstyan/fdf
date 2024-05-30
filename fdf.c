#include "fdf.h"

int win_hooks(int keycode, t_all *a)
{
    if(keycode == OFF_ESC)
    {
        //mlx_destroy_image(a->mlx, img.img);
        mlx_clear_window(a->mlx, a->mlx_win);
        mlx_destroy_window(a->mlx, a->mlx_win);
        exit(0);
    }
    if(keycode == OFF_X)
    {
        //mlx_destroy_image(a->mlx, img.img);
        mlx_clear_window(a->mlx, a->mlx_win);
        mlx_destroy_window(a->mlx, a->mlx_win);
        exit(0);
    }
    return(0);
}

void get_mlx_data(t_all *a)
{
    t_img img; 

    a->mlx = mlx_init();
    a->mlx_win = mlx_new_window(a->mlx, 1920, 1080, "MinilibX");
    img.img = mlx_new_image(a->mlx , 1280, 720);
    //img.addr = mlx_get_data_addr(img.img, 0, 0, 0);
    // mlx_put_image_to_window(a->mlx, a->mlx_win, img.img, 0, 0);
    mlx_hook(a->mlx_win, KEY_PRESS, KEY_PRESS_MASK, win_hooks, a);
    //mlx_hook(a->mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, win_hooks, a);
    mlx_loop(a->mlx);
}