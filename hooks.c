#include "fdf.h"

int win_hooks(int keycode, t_mlx *mlxparams)
{
    if(keycode == OFF_ESC)
    {
        mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
        mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
        exit(0);
    }
    return(0);
}

int close_window(t_mlx *mlxparams)
{
    mlx_clear_window(mlxparams->mlx, mlxparams->mlx_win);
    mlx_destroy_window(mlxparams->mlx, mlxparams->mlx_win);
    exit(0);
    return(0);
}