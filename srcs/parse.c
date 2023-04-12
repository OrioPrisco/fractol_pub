/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:57:29 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:59 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fractol.h"
#include "fractals.h"
#include "parse.h"

//ideally, should join all the fractal name
static const char	*g_fractals
	= "<mandelbrot|julia|ship|julia ship|metamandelbrot|julia meta>";

static void	print_usage(t_parse_error error)
{
	if (error == NO_FRACTAL_NAME)
		ft_printf("Error : No Name Provided\n");
	if (error == BAD_FRACTAL_NAME)
		ft_printf("Error : Bad Fractal Name\n");
	if (error == NO_JULIA_PARAMS)
		ft_printf("Error : Julia requires 2 parameters\n");
	if (error == BAD_JULIA_PARAMS)
		ft_printf("Error : Arguments for Julia have to be doubles\n");
	ft_printf
		("Usage : ./fractol %s <params>\n", g_fractals);
}

int	parse(int argc, char **argv, t_env *env)
{
	char	*endptr;

	if (argc < 2)
		return (print_usage(NO_FRACTAL_NAME), 1);
	if (assign_fractal(argv[1], &env->fractal))
		return (print_usage(BAD_FRACTAL_NAME), 1);
	if (!ft_strncmp("julia", argv[1], ft_strlen("julia")))
	{
		if (argc < 4)
			return (print_usage(NO_JULIA_PARAMS), 1);
		env->camera.params.julia_c.real = ft_strtold(argv[2], &endptr);
		if (*endptr)
			return (print_usage(BAD_JULIA_PARAMS), 1);
		env->camera.params.julia_c.imag = ft_strtold(argv[3], &endptr);
		if (*endptr)
			return (print_usage(BAD_JULIA_PARAMS), 1);
	}
	return (0);
}
