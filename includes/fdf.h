/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:53:24 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/07 22:52:38 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include <sys/stat.h> 
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coord;

typedef struct		s_param
{
	void			*id;
	void			*win;
	int				**tab;
	int				height;
	int				width;
	int				alt;
	int				nb_line;
	int				nb_col;
	int				color;
	int				dep_x;
	int				dep_y;
	float			zoom;
	t_coord			coord;
}					t_param;


void				init_struct_mlx(t_param **mlx);
void				init_mlx(t_param **mlx);
void				core(t_param **mlx);
int					manage_key(int keycode, t_param **mlx);


#endif
