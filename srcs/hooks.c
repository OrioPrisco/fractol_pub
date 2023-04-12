/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:01:14 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:54 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"
#include "fractol.h"
#include "mlx.h"
#include "fractals.h"
#include "color_chunk.h"
#include <stdlib.h>
#include <stdint.h>

void	draw_3b1b_dbg(t_env *env);

int	my_loop_hook(t_env *env)
{
	switch_frame(env);
	if (env->camera.chunk && env->camera.iter != SIZE_MAX)
	{
		if (deepen_chunk(&env->camera, env->camera.chunk, env->fractal))
		{
			free_chunk(env->camera.chunk, 1);
			env->camera.chunk = 0;
		}
	}
	cpy_img(env->frame, &env->camera.work_buffer);
	mlx_put_image_to_window(
		env->mlx, env->win, env->frame->img, 0, 0);
	return (0);
}

void	draw(t_env *env)
{
	switch_frame(env);
	if (env->camera.debug & DBG_WINDING)
		draw_3b1b_dbg(env);
	else
	{
		if (env->camera.chunk)
			recolor_chunks
				(&env->camera.work_buffer, env->camera.chunk, &env->camera);
		else
			env->camera.chunk = boundary_trace_fractal
				(&env->camera, env->fractal);
	}
	cpy_img(env->frame, &env->camera.work_buffer);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(
		env->mlx, env->win, env->frame->img, 0, 0);
}

int	quit_prg(t_env *env)
{
	if (!env->mlx)
		exit(0);
	if (env->frame1.img)
		mlx_destroy_image(env->mlx, env->frame1.img);
	if (env->frame2.img)
		mlx_destroy_image(env->mlx, env->frame2.img);
	if (env->camera.work_buffer.img)
		mlx_destroy_image(env->mlx, env->camera.work_buffer.img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->camera.chunk)
		free_chunk(env->camera.chunk, 1);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
}

int	my_mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 4)
		zoom_camera(&env->camera, 1.1);
	if (button == 5)
		zoom_camera(&env->camera, 0.9);
	if (button == 1 || button == 4)
		move_camera(&env->camera,
			(t_complex){
			(x - env->frame->width / 2) / button
			/ (double)env->frame->width,
			(y - env->frame->height / 2) / button
			/ (double)env->frame->height});
	if (button == 3)
	{
		env->camera.params.julia_c = add_complex(env->camera.top_left,
				(t_complex)
			{x * env->camera.step.real, y * env->camera.step.imag});
		if (env->fractal->julia)
			env->fractal = env->fractal->julia;
	}
	if (button == 1 || button == 3 || button == 4 || button == 5)
		invalidate_chunks(&env->camera);
	return (draw(env), 0);
}

int	my_expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->frame->img, 0, 0);
	return (0);
}
