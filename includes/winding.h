/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winding.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:26:16 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:01 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDING_H
# define WINDING_H

// 0 1 2
// 7   3
// 6 5 4
typedef enum e_direction8
{
	UP_LEFT = 0,
	UP8 = 1,
	UP_RIGHT = 2,
	RIGHT8 = 3,
	DOWN_RIGHT = 4,
	DOWN8 = 5,
	DOWN_LEFT = 6,
	LEFT8 = 7,
}	t_direction8;

int	contains_zero(t_chunk *chunk);
#endif
