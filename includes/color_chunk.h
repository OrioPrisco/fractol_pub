/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_chunk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:42:45 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:00 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_CHUNK_H
# define COLOR_CHUNK_H
# include "complex.h"
# include <stddef.h>

typedef enum e_debug			t_debug;
typedef struct s_img			t_img;
typedef struct s_camera			t_camera;
typedef struct s_fractal		t_fractal;
typedef struct s_param			t_param;

typedef enum e_direction {
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3,
	U = UP,
	L = LEFT,
	D = DOWN,
	R = RIGHT,
}	t_direction;

typedef struct s_iter_result
{
	t_complex	z;
	t_complex	c;
	size_t		iter;
}	t_iter_result;

typedef struct s_chunk_childs	t_chunk_childs;

typedef enum e_chunk_type
{
	NORMAL = 0,
	UNIFORM,
	NO_DEEPEN,
	SMALL,
}	t_chunk_type;

typedef struct s_chunk
{
	t_iter_result	*borders[4];
	t_chunk_childs	*childs;
	size_t			top_left[2];
	size_t			dimensions[2];
	char			filled;
	t_chunk_type	type;
}	t_chunk;

struct s_chunk_childs
{
	t_chunk	c1;
	t_chunk	c2;
};

void	color_bound(t_img *img, t_chunk *chunk, int color);
void	color_uniform_chunk(t_img *img, t_chunk *chunk, t_camera *camera);
void	color_small_chunk(t_img *img, t_chunk *chunk, t_camera *camera);
void	recolor_chunks(t_img *img, t_chunk *chunk, t_camera *camera);
void	color_smooth_chunk(t_img *img, t_chunk *chunk, t_camera *camera,
			const t_fractal *fractal);

#endif
