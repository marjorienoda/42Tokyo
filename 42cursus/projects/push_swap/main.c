#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int start;
	t_strategy flag;
	// int bench_flg;
	t_bench bench;
    if(argc < 2)
		return(0);

	is_valid_input(argc, argv);
	start = get_start_pos(argc, argv);
	flag = get_strategy_flag(argc, argv);
	// bench_flg = is_bench(argc, argv);
	init_bench(&bench, get_strategy_flag(argc, argv));
	printf("start: %d \n", start);
	printf("flag: %d \n", flag);
	ft_printf("my ft_printf strg_flag: %d\n", 2, bench.strg_flag);
	// printf("bench: %d \n", bench_flg);
	// printf("disorder: %f\n", bench.disorder);
	// printf("total_ops: %d\n", bench.total_ops);
	print_bench_mode(&bench);

	return(0);
}

