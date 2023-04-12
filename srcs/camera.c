/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:02:53 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:52 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "fractals.h"

void	invalidate_chunks(t_camera *camera)
{
	if (!(camera->debug & DBG_WINDING))
		camera->iter = 10;
	if (camera->chunk)
	{
		free_chunk(camera->chunk, 1);
		camera->chunk = 0;
	}
}

void	update_camera(t_camera *camera)
{
	if (camera->debug & DBG_X_FLIP)
		camera->step.real = -(1 / camera->scale);
	else
		camera->step.real = (1 / camera->scale);
	if (camera->debug & DBG_Y_FLIP)
		camera->step.imag = (1 / camera->scale);
	else
		camera->step.imag = -(1 / camera->scale);
	camera->top_left.real = (camera->center.real
			- ((camera->work_buffer.width * camera->step.real) / 2));
	camera->top_left.imag = (camera->center.imag
			- ((camera->work_buffer.height * camera->step.imag) / 2));
	invalidate_chunks(camera);
}

void	zoom_camera(t_camera *camera, double scale)
{
	camera->scale *= scale;
	update_camera(camera);
}

void	move_camera(t_camera *camera, t_complex movement)
{
	movement.real *= camera->work_buffer.width * camera->step.real;
	movement.imag *= camera->work_buffer.height * camera->step.imag;
	camera->center = add_complex(camera->center, movement);
	update_camera(camera);
}
