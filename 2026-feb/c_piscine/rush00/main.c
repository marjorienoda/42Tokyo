#include <stdio.h>
#include <unistd.h>

void rush(int x, int y)
{
    int v;
    int h;

    v = 1;
    while (v <= y)
    {
        h = 1;
        while (h <= x)
        {
            if (v == 1 || v == y)
            {  
                if (h == 1)
                {
                    write(1, "A", 1);
                }
                else if (h == x)
                {
                    write (1, "C", 1);
                }
                else
                {
                    write(1, "B", 1);
                }
            }
            else
            {
                if (h == 1 || h == x)
                {
                    write(1, "B", 1);
                }
                else
                {
                    write(1, " ", 1);
                }
            }
            h++;
        }
        write(1, "\n", 1);
        v++;
    }
};

int    main(void)
{
    rush(4, 4);
    return (0);
}