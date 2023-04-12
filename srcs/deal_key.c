/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:09:51 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"
#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "complex.h"

static void	deal_key_dbg(int key, t_env *env)
{
	if (key == XK_F1 || key == XK_F8 || key == XK_F9 || key == XK_m
		|| key == XK_p || key == XK_o || key == XK_l || key == XK_F3
		|| key == XK_i || key == XK_k)
		invalidate_chunks(&env->camera);
	if (key == XK_F1)
			env->camera.debug = env->camera.debug ^ DBG_WINDING;
	if (key == XK_F2)
		env->camera.debug = env->camera.debug ^ DBG_CHUNK_BORDERS;
	if (key == XK_F3)
		env->camera.debug = env->camera.debug ^ DBG_SMOOTH_COLOR;
	if (key == XK_F4)
		env->camera.debug = env->camera.debug ^ DBG_SHOW_NO_DEEPEN;
	if (key == XK_F5)
		next_palette(&env->camera.palette);
	if (key == XK_F6)
		env->camera.palette.color_shift ++;
	if (key == XK_F7)
		return (invalidate_chunks(&env->camera),
			switch_fractal(&env->fractal));
	if (key == XK_F8)
		env->camera.debug = env->camera.debug ^ DBG_X_FLIP;
	if (key == XK_F9)
		env->camera.debug = env->camera.debug ^ DBG_Y_FLIP;
	if (key == XK_F8 || key == XK_F9)
		update_camera(&env->camera);
}

static void	deal_param_keys(int key, t_env *env)
{
	if (key == XK_p)
		env->camera.params.mandelbrot_heads++;
	if (key == XK_m && env->camera.params.mandelbrot_heads != 0)
		env->camera.params.mandelbrot_heads--;
	if (key == XK_o)
		env->camera.params.meta_mandelbrot_level++;
	if (key == XK_l && env->camera.params.meta_mandelbrot_level != 0)
		env->camera.params.meta_mandelbrot_level--;
	if (key == XK_i)
		env->camera.params.meta_mandelbrot_power += 0.01;
	if (key == XK_k)
		env->camera.params.meta_mandelbrot_power -= 0.01;
}

int	deal_key(int key, t_env *env)
{
	if (key == XK_8)
		zoom_camera(&env->camera, 1.1);
	if (key == XK_slash)
		zoom_camera(&env->camera, 0.9);
	if (key == XK_w || key == XK_Up)
		move_camera(&env->camera, (t_complex){0, -0.05});
	if (key == XK_s || key == XK_Down)
		move_camera(&env->camera, (t_complex){0, 0.05});
	if (key == XK_a || key == XK_Left)
		move_camera(&env->camera, (t_complex){-0.05, 0});
	if (key == XK_d || key == XK_Right)
		move_camera(&env->camera, (t_complex){0.05, 0});
	if (key == XK_Escape)
		quit_prg(env);
	deal_key_dbg(key, env);
	deal_param_keys(key, env);
	draw(env);
	return (0);
}
