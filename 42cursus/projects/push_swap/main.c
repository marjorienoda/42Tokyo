#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	
    if(argc < 2)
		return(0);

	i = is_valid_input(argc, argv);
	return(i);
}