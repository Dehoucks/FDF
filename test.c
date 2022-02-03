#include "minilibx/mlx.h"

int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	mlx = mlx_new_window(mlx, 400, 400, "42 test window");

	mlx_loop(mlx);
}