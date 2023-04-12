/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:21 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:00 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# include "fractol_image.h"
# include "camera.h"
# include "fractals.h"
# include <stdbool.h>

typedef struct s_env
{
	void			*win;
	void			*mlx;
	t_img			*frame;
	t_img			frame1;
	t_img			frame2;
	t_camera		camera;
	const t_fractal	*fractal;
}	t_env;

int		init_env(t_env *env);
void	switch_frame(t_env *env);
void	next_palette(t_palette *palette);
void	switch_fractal(const t_fractal **env);
bool	assign_fractal(const char *name, const t_fractal **fractal);
void	default_palette(t_palette *palette);

#endif
