/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:00 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:53 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "math.h"

t_complex_part	complex_mod(t_complex num)
{
	return (sqrtl(num.real * num.real + num.imag * num.imag));
}

t_complex_part	complex_mod2(t_complex num)
{
	return (num.real * num.real + num.imag * num.imag);
}

t_complex	add_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return (result);
}

t_complex	square_complex(t_complex num)
{
	t_complex	ret;

	ret.real = (num.real * num.real) - (num.imag * num.imag);
	ret.imag = 2 * num.real * num.imag;
	return (ret);
}
