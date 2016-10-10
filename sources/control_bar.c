/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:59:22 by jpirsch           #+#    #+#             */
/*   Updated: 2016/03/10 01:55:37 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"

void	bar_button(t_env *e, int x, int y)
{
	ft_putstr("x : ");
	ft_putnbr(x);
	ft_putendl("");
	ft_putstr("y : ");
	ft_putnbr(y);
	ft_putendl("");
	(x > 260 && x < 300 && y > 920 && y < 960) ? e->max_iter *= 2 : 1;
	(x > 460 && x < 520 && y > 920 && y < 960) ? e->fract_type++ : 1;
	(e->fract_type > 3) ? e->fract_type = 0 : 1;
	(x > 720 && x < 760 && y > 920 && y < 960) ? e->depth += 1 : 1;
	(e->depth > 20) ? e->depth = 1 : 1;
	(x > 960 && x < 1000 && y > 920 && y < 960) ? e->sat += 0.1 : 1;
}

void	btext(t_env *e)
{
	int i;
	char *str;
	char *str2;

	i = 0;
	str2 = ft_strdup("o");
	while (i < 5)
	{
		str = (i == 0) ? str = ft_strdup("Iterations") : str;
		str = (i == 1) ? str = ft_strdup("Fractal") : str;
		str = (i == 2) ? str = ft_strdup("Depth") : str;
		str = (i == 3) ? str = ft_strdup("Saturation") : str;
		str = (i == 4) ? str = ft_strdup("Value") : str;
		mlx_string_put(e->mlx, e->win, 220 + i * 240, 900, 0xFFFFFF, str);
		mlx_string_put(e->mlx, e->win, 255 + i * 240, 925, 0x000000, str2);
		i++;
	}
}

void	button(t_env *e, int i, int tmp, int k)
{
	int j;

	while (k < 5)
	{
		e->r = 120;
		e->g = 100;
		e->b = 100;
		tmp += 240;
		i = 920;
		while (i < 960)
		{
			j = tmp;
			while (j < tmp + 40)
			{
				px_to_img(e, j, i);
				j++;
			}
			e->r--;
			e->g--;
			e->b--;
			i++;
		}
		k++;
	}
}

void	control_bar(t_env *e)
{
	int	i;
	int	j;

	e->r = 80;
	e->g = 80;
	e->b = 80;
	i = 900;
	while (i < 980)
	{
		j = 0;
		while (j < 1440)
		{
			px_to_img(e, j, i);
			j++;
		}
		i++;
	}
	button(e, 920, 0, 0);
	btext(e);
}
