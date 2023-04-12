/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metamandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:54:05 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:55 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "params.h"
#include "camera.h"
#include "color.h"
#include <math.h>

static t_complex	metamandelbrot(t_complex z, t_complex c, size_t lvl,
	const t_param *data)
{
	if (lvl == 0)
		return (add_complex(complex_pow(z, data->meta_mandelbrot_power), c));
	return (metamandelbrot(metamandelbrot(z, c, lvl - 1, data),
			metamandelbrot(c, z, lvl - 1, data), 0, data));
}

size_t	metamandelbrot_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data)
{
	size_t		iter;
	t_complex	num;

	num = *z;
	iter = iterations;
	(void)data;
	while (iter)
	{
		num = metamandelbrot(num, c, data->meta_mandelbrot_level, data);
		if (complex_mod2(num) > (RADIUS * RADIUS))
			return (*z = num, iterations - iter);
		iter--;
	}
	return (*z = num, iterations);
}
