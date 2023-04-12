/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:53:38 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:00 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

//the definition of t_complex is needed
# include "complex.h"
# include <stddef.h>
# define RADIUS 6

typedef struct s_chunk		t_chunk;
typedef struct s_camera		t_camera;
typedef struct s_param		t_param;
typedef struct s_fractal	t_fractal;
typedef size_t				t_f_iterator (t_complex *, t_complex, size_t,
			const t_param *);
typedef int					t_f_repair (t_chunk *);
typedef int					t_f_smooth (t_complex, const t_camera *);

//leave julia to null if this is a julia function
//TODO : specify what kinf of optimization should be used by default
//leave should_repair null if fractal cannot be repaired
//smooth color currently unused
typedef struct s_fractal
{
	t_f_iterator	*iterate;
	const t_fractal	*julia;
	t_f_repair		*should_repair;
	t_f_smooth		*smooth_color;
	const char		*name;
}	t_fractal;

size_t	mandelbrot_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
int		mandelbrot_smooth(t_complex z, const t_camera *camera);
size_t	julia_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
int		julia_smooth(t_complex z, const t_camera *camera);
size_t	metamandelbrot_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
size_t	metajulia_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
size_t	burning_ship_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
size_t	julia_ship_iterate(t_complex *z, t_complex c, size_t iterations,
			const t_param *data);
t_chunk	*boundary_trace_fractal(t_camera *camera,
			const t_fractal *f);
int		deepen_chunk(t_camera *camera, t_chunk *chunk,
			const t_fractal *f);
//if you want to destroy a chunk given by boundary_trace_fractal, it is always
//the top chunk. therefore set is_top_chunk to 1
void	free_chunk(t_chunk *chunk, int is_top_chunk);

#endif
