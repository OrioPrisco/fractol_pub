/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:09:31 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:00 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stddef.h>

typedef struct s_camera	t_camera;

int	get_color(size_t iter, const t_camera *camera);
int	smooth_color(double smooth_iter, const t_camera *camera);
int	multiply_color(int color, double multiplication);

#endif
