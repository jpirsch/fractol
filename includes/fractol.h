/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:21:11 by jpirsch           #+#    #+#             */
/*   Updated: 2015/03/17 19:15:38 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					size_line;
	int					depth;
	int					endian;
	double				decalx;
	double				decaly;
	double				x;
	double				y;
	double				zoom;
	int					fract_type;
	int					max_iter;
	double				h;
	double				s;
	double				v;
	double				sat;
	double				value;
	int					pause;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_env;

typedef struct			s_pt
{
	double				x;
	double				y;
}						t_pt;

void					px_to_img(t_env *e, int x, int y);
void					print_state(t_env *e);
void					env(int	fract);
void					set_env_struct(t_env *e);
void					draw(t_env *e);
void					draw_tree(t_env *e, t_pt start, double angle,
						int depth);
void					btext(t_env *e);
void					bar_button(t_env *e, int x, int y);
void					hsv_to_rgb(t_env *e, double p, double q, double t);
void					hsv0(t_env *e, int p, int t);
void					hsv1(t_env *e, int p, int q);
void					hsv2(t_env *e, int p, int t);
void					hsv3(t_env *e, int p, int q);
void					hsv4(t_env *e, int p, int t);
void					control_bar(t_env *e);
#endif
