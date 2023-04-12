/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:54:05 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:55 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "params.h"
#include "color.h"
#include "camera.h"
#include <math.h>

size_t	julia_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data)
{
	(void)c;
	return (mandelbrot_iterate(z, data->julia_c, iterations, data));
}

int	julia_smooth(t_complex z, const t_camera *camera)
{
	double	smooth_iter;
	size_t	i;

	i = 0;
	smooth_iter = expl(-complex_mod(z));
	while (i < camera->iter)
	{
		i++;
		if (!mandelbrot_iterate
			(&z, camera->params.julia_c, 1, &camera->params))
			return (smooth_color(smooth_iter, camera));
		smooth_iter += expl(-complex_mod(z));
	}
	return (0);
}
