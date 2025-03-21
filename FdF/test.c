#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 500, 500, "Test");
    void *img = mlx_new_image(mlx, 500, 500);

    printf("Destroying image...\n");
    mlx_destroy_image(mlx, img);
    printf("Destroying window...\n");
    mlx_destroy_window(mlx, win);
    printf("Destroying display...\n");
    mlx_destroy_display(mlx);
    free(mlx);

    return 0;
}

