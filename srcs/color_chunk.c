/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:59:24 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_chunk.h"
#include "fractol_image.h"
#include "camera.h"
#include "color.h"
#include "fractals.h"
#include "fractol.h"
#include "mlx.h"

void	color_bound(t_img *img, t_chunk *chunk, int color)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < chunk->dimensions[1])
	{
		my_mlx_pixel_put(img, chunk->top_left[0],
			y + chunk->top_left[1], color);
		my_mlx_pixel_put(img, chunk->top_left[0]
			+ chunk->dimensions[0], y + chunk->top_left[1], color);
		y++;
	}
	x = 0;
	while (x < chunk->dimensions[0])
	{
		my_mlx_pixel_put(img, chunk->top_left[0]
			+ x, chunk->top_left[1], color);
		my_mlx_pixel_put(img, chunk->top_left[0]
			+ x, chunk->top_left[1] + chunk->dimensions[1], color);
		x++;
	}
}

void	color_uniform_chunk(t_img *img, t_chunk *chunk, t_camera *camera)
{
	size_t	y;
	int		color;

	if (chunk->borders[0][0].iter != camera->iter)
		chunk->type = UNIFORM;
	y = chunk->top_left[1];
	color = get_color(chunk->borders[0][0].iter, camera);
	while (y < chunk->top_left[1] + chunk->dimensions[1])
	{
		img_put_line(img,
			line(chunk->top_left[0], y, chunk->dimensions[0], color));
		y++;
	}
	if (camera->debug & DBG_CHUNK_BORDERS)
		color_bound(img, chunk, 0x00ff0000);
}

void	color_small_chunk(t_img *img, t_chunk *chunk, t_camera *camera)
{
	size_t	x;
	size_t	y;
	int		color;

	y = 0;
	chunk->type = SMALL;
	while (y < chunk->dimensions[1])
	{
		x = 0;
		while (x < chunk->dimensions[0])
		{
			if (y == 0)
				color = get_color(chunk->borders[U][x].iter, camera);
			else if (x == 0)
				color = get_color(chunk->borders[L][y].iter, camera);
			if (color == 0x0)
				chunk->type = NORMAL;
			my_mlx_pixel_put
				(img, x + chunk->top_left[0], y + chunk->top_left[1], color);
			x++;
		}
		y++;
	}
	if (camera->debug & DBG_CHUNK_BORDERS)
		color_bound(img, chunk, 0x00ff0000);
}

void	recolor_chunks(t_img *img, t_chunk *chunk, t_camera *camera)
{
	if (chunk->childs)
	{
		recolor_chunks(img, &chunk->childs->c1, camera);
		recolor_chunks(img, &chunk->childs->c2, camera);
		return ;
	}
	if (chunk->type == UNIFORM)
		return ((void)color_uniform_chunk(img, chunk, camera));
	color_small_chunk(img, chunk, camera);
}

void	color_smooth_chunk(t_img *img, t_chunk *chunk, t_camera *camera,
	const t_fractal *fractal)
{
	size_t		i;
	t_complex	z;

	if (!fractal->smooth_color)
		return (color_small_chunk(img, chunk, camera));
	i = 0;
	while (i < (chunk->dimensions[0] * chunk->dimensions[1]))
	{
		z = add_complex(add_complex(camera->top_left, (t_complex){
					(i % chunk->dimensions[0]) * camera->step.real,
					(i / chunk->dimensions[0]) * camera->step.imag}),
				(t_complex){chunk->top_left[0] * camera->step.real,
				chunk->top_left[1] * camera->step.imag});
		my_mlx_pixel_put(img,
			chunk->top_left[0] + (i % chunk->dimensions[0]),
			chunk->top_left[1] + (i / chunk->dimensions[0]),
			fractal->smooth_color(z, camera));
		i++;
	}
	if (camera->debug & DBG_CHUNK_BORDERS)
		color_bound(img, chunk, 0x00ff0000);
}
