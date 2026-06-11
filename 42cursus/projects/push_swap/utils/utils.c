/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:10:55 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:10:57 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", 2, str);
	exit(1);
}

int	get_start_pos(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			i++;
		else
			return (i);
	}
	return (i);
}

static int	is_flag(char *arg, char *flag)
{
	return (ft_strncmp(arg, flag, ft_strlen(flag)) == 0);
}

int	is_bench(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_flag(argv[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}

t_strategy	get_strategy_flag(int argc, char **argv)
{
	t_strategy	strg_flag;
	int			i;

	i = 0;
	strg_flag = ADAPTIVE;
	while (i < argc)
	{
		if (is_flag(argv[i], "--simple"))
			strg_flag = SIMPLE;
		else if (is_flag(argv[i], "--medium"))
			strg_flag = MEDIUM;
		else if (is_flag(argv[i], "--complex"))
			strg_flag = COMPLEX;
		else if (is_flag(argv[i], "--adaptive"))
			strg_flag = ADAPTIVE;
		i++;
	}
	return (strg_flag);
}
