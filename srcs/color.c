/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:33:28 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include  <math.h>

int	get_color(size_t iter, const t_camera *camera)
{
	if (iter == camera->iter)
		return (0);
	return (camera->palette.data->colors[(iter + camera->palette.color_shift)
			% camera->palette.data->number_of_colors]);
}

int	multiply_color(int color, double multiplication)
{
	int	red;
	int	green;
	int	blue;

	red = (color >> 16) & 0xff;
	green = (color >> 8) & 0xff;
	blue = (color >> 0) & 0xff;
	red *= multiplication;
	green *= multiplication;
	blue *= multiplication;
	return ((red << 16) + (green << 8) + blue);
}

int	smooth_color(double smooth_iter, const t_camera *camera)
{
	long	iter_whole;
	double	iter_decimal;

	if (smooth_iter >= camera->iter)
		return (0);
	if (smooth_iter <= 1)
		return (get_color(0, camera));
	iter_whole = (long)smooth_iter;
	iter_decimal = smooth_iter - iter_whole;
	return (
		multiply_color(
			get_color(iter_whole, camera), iter_decimal)
		+ multiply_color(
			get_color(iter_whole - 1, camera), 1.0f - iter_decimal));
}
