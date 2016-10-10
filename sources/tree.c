/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:28:29 by jpirsch           #+#    #+#             */
/*   Updated: 2016/03/22 00:40:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	putl(t_env *e, t_pt start, t_pt end)
{
	double	dd;
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		if (x < 1440 && x > 0 && y > 0 && y < 900)
			px_to_img(e, ABS(x), ABS(y));
		x += dx;
		y += dy;
	}
}

void	draw_tree(t_env *e, t_pt start, double angle, int depth)
{
	double	x2;
	double	y2;
	t_pt	end;

	if (depth > 0)
	{
		x2 = start.x + (cos(angle) * depth * e->x * 10);
		y2 = start.y + (sin(angle) * depth * e->y * 15.0);
		end.x = x2;
		end.y = y2;
		putl(e, start, end);
		draw_tree(e, end, angle - (M_PI / 8), depth - 1);
		draw_tree(e, end, angle + (M_PI / 8), depth - 1);
	}
}
