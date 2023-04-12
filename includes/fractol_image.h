/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:34:02 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:01 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_IMAGE_H
# define FRACTOL_IMAGE_H
# include "stddef.h"

typedef struct s_img
{
	void			*img;
	unsigned char	*data;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				height;
	int				width;
}	t_img;

//only there because of norm
typedef struct s_line
{
	size_t	x;
	size_t	y;
	size_t	size;
	int		color;
}	t_line;

t_line	line(size_t x, size_t y, size_t size, int color);
void	my_mlx_pixel_put(t_img *img, size_t x, size_t y, int color);
void	cpy_img(t_img *dest, const t_img *src);
void	img_put_line(t_img *img, t_line line);

#endif
