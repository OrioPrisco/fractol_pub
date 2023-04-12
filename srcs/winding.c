/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:51:38 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:59 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_chunk.h"
#include "complex.h"
#include "winding.h"
#include <math.h>

//returns the rough direction of a vector
static t_direction8	direction(t_complex num)
{
	double	cardinality;

	cardinality = fabsl(num.real / num.imag);
	if (cardinality < .25)
	{
		if (num.imag > 0)
			return (UP8);
		return (DOWN8);
	}
	if (cardinality > 4)
	{
		if (num.real > 0)
			return (RIGHT8);
		return (LEFT8);
	}
	if (num.imag > 0 && num.real > 0)
		return (UP_RIGHT);
	if (num.imag < 0 && num.real > 0)
		return (DOWN_RIGHT);
	if (num.imag > 0 && num.real < 0)
		return (UP_LEFT);
	return (DOWN_LEFT);
}

//1 represents 1/8 of a turn
static	int	angle(t_direction8 a, t_direction8 b)
{
	if (a == 0 && b == 7)
		return (-1);
	if (a == 7 && b == 0)
		return (1);
	return (b - a);
}

int	contains_zero(t_chunk *chunk)
{
	int				winding;
	t_direction8	previous_angle;
	t_direction8	current_angle;
	size_t			i;
	t_direction		dir;

	dir = 0;
	winding = 0;
	while (dir < 4)
	{
		previous_angle = direction(chunk->borders[dir][0].z);
		i = 0;
		while (i < chunk->dimensions[dir % 2])
		{
			current_angle = direction(chunk->borders[dir][i].z);
			if (dir == UP || dir == RIGHT)
				winding += angle(previous_angle, current_angle);
			else
				winding -= angle(previous_angle, current_angle);
			previous_angle = current_angle;
			i++;
		}
		dir++;
	}
	return (winding > 5 || winding < -5);
}
