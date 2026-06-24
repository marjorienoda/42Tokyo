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
}					t_strategy;

typedef struct bench_mode
{
	double			disorder;
	t_strategy		strategy_flag;
	t_strategy		actual_flag;
	int				total_ops;
	int				sa_ops;
	int				sb_ops;
	int				ss_ops;
	int				pa_ops;
	int				pb_ops;
	int				ra_ops;
	int				rb_ops;
	int				rr_ops;
	int				rra_ops;
	int				rrb_ops;
	int				rrr_ops;
}					t_bench;

typedef struct s_chunk
{
	int				min;
	int				max;
	int				size;
}					t_chunk;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
	====== LIBFT ======
*/

long				ft_atoil(const char *str);
int					ft_isdigit(int c);
int					ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putdouble_fd(double n, int fd);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_printf(const char *str, int fd, ...);

/*
	====== UTILS ======
*/

void				ft_error(char *str);
void				is_valid_input(int argc, char **argv);
int					get_start_pos(int argc, char **argv);
int					is_bench(int argc, char **argv);
t_strategy			get_strategy_flag(int argc, char **argv);
void				init_bench(t_bench *bench, t_strategy flag);
void				print_bench_mode(t_bench *bench);
void				ft_free_stack(t_node *stack);
t_node				*stack_last(t_node *node);
t_node				*create_new_node(int nb);
t_node				*init_stack_a(int argc, char **argv, int start);
void				stack_add_bottom(t_node **stack, t_node *new);
int					stack_size(t_node *stack);

/*
	====== OPERATIONS ======
*/

void				swap_op(t_node **stack);
void				rotate_op(t_node **stack);
void				reverse_rotate_op(t_node **stack);
void	push_to_top(t_node **stack_a, t_node *node_to_move);
void				sa_op(t_node **stack_a, t_bench *bench);
void				sb_op(t_node **stack_b, t_bench *bench);
void				ss_op(t_node **stack_a, t_node **stack_b, t_bench *bench);
void				pb_op(t_node **stack_a, t_node **stack_b, t_bench *bench);
void				pa_op(t_node **stack_a, t_node **stack_b, t_bench *bench);
void				ra_op(t_node **stack_a, t_bench *bench);
void				rb_op(t_node **stack_b, t_bench *bench);
void				rr_op(t_node **stack_a, t_node **stack_b, t_bench *bench);
void				rra_op(t_node **stack_a, t_bench *bench);
void				rrb_op(t_node **stack_b, t_bench *bench);
void				rrr_op(t_node **stack_a, t_node **stack_b, t_bench *bench);

int					*create_array_tmp(t_node *stack_a, int size);
void				swap(int *prev, int *next);
int					*bubble_sort(int *array, int size);
void				fill_index_stack(t_node *stack_a, int *array, int size);
int					get_max_bits(int size);

int					ft_chunk(int size);
void				move_max_to_top(t_node **stack_b, t_bench *bench);
void				push_chunks(t_node **stack_a, t_node **stack_b,
						int chunk_size, t_bench *bench);
double	ft_disorder(t_node *stack, t_bench *bench);
void				simple_strag(t_node **stack_a, t_node **stack_b,
						t_bench *bench);
void				medium_strag(t_node **a, t_node **b, t_bench *bench);						
void				complex_strag(t_node **stack_a, t_node **stack_b,
						t_bench *bench);
void	adaptive_strag(t_node **stack_a, t_node **stack_b, t_bench *bench);
#endif