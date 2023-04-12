/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:14:29 by OrioPriscc        #+#    #+#             */
/*   Updated: 2023/04/12 11:56:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

static t_complex_polar	canonical_to_polar(t_complex canonical)
{
	t_complex_polar	polar;

	polar.radius = complex_mod(canonical);
	if (polar.radius)
		polar.theta = acosl(canonical.real / polar.radius);
	else
		polar.theta = 0;
	if (canonical.imag < 0)
		polar.theta *= -1;
	return (polar);
}

static t_complex	polar_to_canonical(t_complex_polar polar)
{
	t_complex	canonical;

	canonical.real = polar.radius * cosl(polar.theta);
	canonical.imag = polar.radius * sinl(polar.theta);
	return (canonical);
}

t_complex	complex_pow(t_complex num, double pow)
{
	t_complex_polar	polar;

	polar = canonical_to_polar(num);
	polar.theta *= pow;
	polar.radius = powl(polar.radius, pow);
	return (polar_to_canonical(polar));
}
