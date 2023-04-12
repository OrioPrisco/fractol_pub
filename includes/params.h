/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:38:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:01 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "complex.h"
# include <stddef.h>

typedef struct s_param
{
	t_complex	julia_c;
	size_t		mandelbrot_heads;
	size_t		meta_mandelbrot_level;
	double		meta_mandelbrot_power;
}	t_param;

#endif
