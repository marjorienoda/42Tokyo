/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:11:11 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:11:13 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}				t_strategy;

typedef struct bench_mode
{
	double		disorder;
	t_strategy	strategy_flag;
	t_strategy	actual_flag;
	int			total_ops;
	int			sa_ops;
	int			sb_ops;
	int			ss_ops;
	int			pa_ops;
	int			pb_ops;
	int			ra_ops;
	int			rb_ops;
	int			rr_ops;
	int			rra_ops;
	int			rrb_ops;
	int			rrr_ops;
}				t_bench;

/*
	====== LIBFT ======
*/

long			ft_atoil(const char *str);
int				ft_isdigit(int c);
int				ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putdouble_fd(double n, int fd);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_printf(const char *str, int fd, ...);

/*
	====== UTILS ======
*/

void			ft_error(char *str);
void			is_valid_input(int argc, char **argv);
int				get_start_pos(int argc, char **argv);
int				is_bench(int argc, char **argv);
t_strategy		get_strategy_flag(int argc, char **argv);
void			init_bench(t_bench *bench, t_strategy flag);
void			print_bench_mode(t_bench *bench);

#endif
