/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deepen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:59:37 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:54 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "fractals.h"
#include "color_chunk.h"

static const int	g_deepen_by = 3;

static void	reiterate_chunk_borders(t_camera *camera, t_chunk *chunk,
	const t_fractal *fractal)
{
	t_direction	dir;
	size_t		i;

	dir = -1;
	while (++dir < 4)
	{
		if (chunk->filled & (1 << dir))
			continue ;
		i = 0;
		while (i < chunk->dimensions[dir % 2])
		{
			if (chunk->borders[dir][i].iter == camera->iter - g_deepen_by)
			{
				chunk->borders[dir][i].iter += fractal->iterate
					(&chunk->borders[dir][i].z, chunk->borders[dir][i].c,
						g_deepen_by, &camera->params);
			}
			i++;
		}
	}
}

int	boundary_trace_fractal_r(t_camera *camera, t_chunk *chunk,
				const t_fractal *fractal);

static int	deepen_chunk_r(t_camera *camera, t_chunk *chunk,
	const t_fractal *fractal)
{
	if (camera->debug & DBG_SHOW_NO_DEEPEN && chunk->type != NORMAL)
		return (color_bound(&camera->work_buffer, chunk, 0x000000ff), 0);
	if (chunk->type != NORMAL)
		return (0);
	if (chunk->childs)
	{
		reiterate_chunk_borders(camera, &chunk->childs->c1, fractal);
		if (deepen_chunk_r(camera, &chunk->childs->c1, fractal))
			return (1);
		if (deepen_chunk_r(camera, &chunk->childs->c2, fractal))
			return (1);
		if (chunk->childs->c1.type && chunk->childs->c2.type)
			chunk->type = NO_DEEPEN;
		return (0);
	}
	return (boundary_trace_fractal_r(camera, chunk, fractal));
}

//pass by how much to deepen ?
//returns 0 on success
//returns 1 on failure, and destroys the t_chunk*
int	deepen_chunk(t_camera *camera, t_chunk *chunk,
	const t_fractal *fractal)
{
	if (chunk->type != NORMAL)
		return (0);
	camera->iter += g_deepen_by;
	reiterate_chunk_borders(camera, chunk, fractal);
	if (deepen_chunk_r(camera, chunk, fractal))
		return (free_chunk(chunk, 1), 1);
	return (0);
}
