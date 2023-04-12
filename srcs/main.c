/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:09:12 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/12 11:56:55 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "fractol_hooks.h"
#include <X11/X.h>
#include "parse.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	if (parse(argc, argv, &env) || init_env(&env))
		quit_prg(&env);
	mlx_key_hook(env.win, &deal_key, &env);
	mlx_expose_hook(env.win, my_expose, &env);
	mlx_hook(env.win, DestroyNotify, StructureNotifyMask, &quit_prg, &env);
	mlx_mouse_hook(env.win, my_mouse_hook, &env);
	mlx_loop_hook(env.mlx, my_loop_hook, &env);
	draw(&env);
	my_expose(&env);
	mlx_loop(env.mlx);
}
