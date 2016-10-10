/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:38:59 by jpirsch           #+#    #+#             */
/*   Updated: 2016/03/10 01:57:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	color(t_env *e, int i, int x1, int y1)
{
	if (i == e->max_iter)
	{
		e->r = 0;
		e->g = 0;
		e->b = 0;
		px_to_img(e, (int)x1, (int)y1);
	}
	else
	{
		e->h = i % 360;
		e->s = e->sat + 1 - (double)i / e->max_iter;
		e->v = e->value + 1 - (double)i / e->max_iter;
		hsv_to_rgb(e, 0, 0, 0);
		px_to_img(e, (int)x1, (int)y1);
	}
}

void	buddhabrot(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	double	modzn;
	double	modc;
	double	tmp;

	i = 0;
//	zn.x = (((double)x1 / 1440) * 3.5 * e->zoom) - e->decalx;
//	zn.y = (((double)y1 / 900) * 2 * e->zoom) - e->decaly;
	zn.x = (((double)x1 / 1440) * 2 * e->zoom) - e->decalx;
	zn.y = (((double)y1 / 900) * 2 * e->zoom) - e->decaly;
	modzn = sqrt((zn.x * zn.x) + (zn.y * zn.y)) / 2;
	c.x = e->x;
	c.y = e->y;
	modc = sqrt((c.x * c.x) + (c.y * c.y)) / 2;
	while (i < e->max_iter && modc * modc < 4)
	{
		tmp = (modc * modc) + modzn;
		if (modc == tmp)
			i = e->max_iter;
		modc = tmp;
		++i;
	}
	color(e, i, x1, y1);
}

void	mandelbrot(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	t_pt	temp;

	i = 0;
//	zn.x = (((double)x1 / 1440) * 3.5 * e->zoom) - e->decalx;
//	zn.y = (((double)y1 / 900) * 2 * e->zoom) - e->decaly;
	zn.x = (((double)x1 / 1440) * 2 * e->zoom) - e->decalx;
	zn.y = (((double)y1 / 900) * 2 * e->zoom) - e->decaly;
	c.x = e->x;
	c.y = e->y;
	while (i < e->max_iter && c.x * c.x + c.y * c.y < 4)
	{
		temp.x = c.x * c.x - c.y * c.y + zn.x;
		temp.y = 2 * c.x * c.y + zn.y;
		if (c.x == temp.y && c.y == temp.y)
			i = e->max_iter;
		c.y = temp.y;
		c.x = temp.x;
		++i;
	}
	color(e, i, x1, y1);
}

void	julia(t_env *e, int x1, int y1)
{
	int		i;
	t_pt	zn;
	t_pt	c;
	t_pt	temp;

	i = 0;
	zn.x = ((double)x1 / 1440 * 3.5 * e->zoom) - e->decalx;
	zn.y = ((double)y1 / 900 * 2 * e->zoom) - e->decaly;
	c.x = e->x;
	c.y = e->y;
	while (i < e->max_iter && zn.x * zn.x + zn.y * zn.y < 4)
	{
		temp.x = zn.x * zn.x - zn.y * zn.y + c.x;
		temp.y = 2 * zn.x * zn.y + c.y;
		if (zn.x == temp.x && zn.y == temp.y)
			i = e->max_iter;
		zn.y = temp.y;
		zn.x = temp.x;
		++i;
	}
	color(e, i, x1, y1);
}

void	loop(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < 900)
	{
		j = 0;
		while (j < 1440)
		{
			if (e->fract_type == 1)
				mandelbrot(e, j, i);
			else if (e->fract_type == 3)
				buddhabrot(e, j, i);
			else
				julia(e, j, i);
			++j;
		}
		++i;
	}
}

void	draw(t_env *e)
{
	t_pt	start;

	ft_bzero(e->data, e->size_line * 900);
	if (e->fract_type == 2)
	{
		start.x = 970 - 100 * e->decalx;
		start.y = 540 - 100 * e->decaly;
		draw_tree(e, start, -(M_PI / 2), e->depth);
		draw_tree(e, start, (M_PI / 2), e->depth);
	}
	else
		loop(e);
	control_bar(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	btext(e);
	mlx_do_sync(e->mlx);
}
