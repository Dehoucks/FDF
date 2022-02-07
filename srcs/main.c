/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:48:52 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/07 23:16:45 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

void	init_mlx(t_param **mlx)
{
	if (!((*mlx)->id = mlx_init()))
	{
		ft_putendl("_INIT_ERROR_");
		exit(EXIT_FAILURE);
	}
	(*mlx)->win = mlx_new_window((*mlx)->id, (*mlx)->height, (*mlx)->width,
			"FdF");
}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

// ** Echap (quit): 53 (touche ESC)
int	manage_key(int keycode, t_param **mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*mlx)->id, (*mlx)->win);
		ft_memdel((void**)mlx);
		ft_putendl("QUIT");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void			core(t_param **mlx)
{
	mlx_hook((*mlx)->win, 2, 3, manage_key, mlx);
	mlx_loop((*mlx)->id);
}

void	draw_map(t_param **mlx)
{
	int		x;
	int		y;

	x = 20;
	y = 10;
	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			mlx_pixel_put(mlx,(*mlx)->win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}

int main()
{
	t_param		*mlx;
	int			x;
	int			y;
	int			fd;
	char		*myline;

	x = 0;
	y = 0;
	fd = open("test_maps/42.fdf", O_RDONLY);
	myline = get_next_line(fd);
	while (myline)
	{
		printf("%s", myline);
		myline = get_next_line(fd);
	}
	mlx = (t_param*)malloc(sizeof(t_param));
	init_struct_mlx(&mlx);
	init_mlx(&mlx);
	draw_map(&mlx);
	core(&mlx);
}