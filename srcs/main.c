/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:48:52 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/08 14:51:36 by rdehouck         ###   ########lyon.fr   */
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

void	draw_map(t_param **mlx, char *myline, int y)
{
	int	i;
	int	zone;

	i = 0;
	while (myline[i])
	{
		zone = i;
		if (myline[i] != '0')
		{
			mlx_pixel_put(mlx,(*mlx)->win, i, y, 0x00FFFFFF);
		}
		i += 1;
	}
}

int main()
{
	t_param		*mlx;
	int			y;
	int			fd;
	char		*myline;


	mlx = (t_param*)malloc(sizeof(t_param));
	init_struct_mlx(&mlx);
	init_mlx(&mlx);
	fd = open("test_maps/42.fdf", O_RDONLY);
	myline = get_next_line(fd);
	y = 0;
	while (myline)
	{
		draw_map(&mlx, myline, y);
		// printf("%s", myline);
		myline = get_next_line(fd);
		y++;
	}
	core(&mlx);
}