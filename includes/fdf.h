/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:53:24 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/07 13:13:52 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

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

#endif
