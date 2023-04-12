/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:54:05 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:52 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <math.h>

size_t	burning_ship_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data)
{
	size_t		iter;
	t_complex	num;

	(void)data;
	num = *z;
	iter = iterations;
	while (iter)
	{
		num = add_complex(
				square_complex(
					(t_complex){
					fabsl(num.real),
					fabsl(num.imag)}),
				c);
		if (complex_mod2(num) > (RADIUS * RADIUS))
			return (*z = num, iterations - iter);
		iter--;
	}
	return (*z = num, iterations);
}
