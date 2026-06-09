#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	// int i;
	int start;

    if(argc < 2)
		return(0);

	is_valid_input(argc, argv);
	start = get_start_pos(argc, argv);
	printf("%d \n", start);
	return(0);
}

