/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:45:19 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/17 12:54:38 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hsv0(t_env *e, int p, int t)
{
	e->r = e->v;
	e->g = t;
	e->b = p;
}

void	hsv1(t_env *e, int p, int q)
{
	e->r = q;
	e->g = e->v;
	e->b = p;
}

void	hsv2(t_env *e, int p, int t)
{
	e->r = p;
	e->g = e->v;
	e->b = t;
}

void	hsv3(t_env *e, int p, int q)
{
	e->r = p;
	e->g = q;
	e->b = e->v;
}

void	hsv4(t_env *e, int p, int t)
{
	e->r = t;
	e->g = p;
	e->b = e->v;
}
