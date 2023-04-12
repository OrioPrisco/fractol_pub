/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:02:31 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:57:01 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum e_parse_error
{
	NO_FRACTAL_NAME,
	BAD_FRACTAL_NAME,
	NO_JULIA_PARAMS,
	BAD_JULIA_PARAMS
}	t_parse_error;

typedef struct s_env	t_env;

int	parse(int argc, char **argv, t_env *env);

#endif
