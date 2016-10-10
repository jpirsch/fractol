/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:42:57 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/17 12:57:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

void	hsv_to_rgb(t_env *e, double p, double q, double t)
{
	double	hh;
	double	ff;
	int		i;

	hh = e->h / 60;
	i = floor(hh);
	ff = hh - i;
	p = e->v * (1.0 - e->s);
	q = e->v * (1.0 - (e->s * ff));
	t = e->v * (e->s * (1.0 - ff));
	p *= 250;
	q *= 250;
	t *= 250;
	(i == 0) ? hsv0(e, p, t) : 1;
	(i == 1) ? hsv1(e, p, q) : 1;
	(i == 2) ? hsv2(e, p, t) : 1;
	(i == 3) ? hsv3(e, p, q) : 1;
	(i == 4) ? hsv4(e, p, t) : 1;
	if (i == 5)
	{
		e->r = e->v;
		e->g = p;
		e->b = q;
	}
}
