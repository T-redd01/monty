#include "monty.h"

size_t line_count(void)
{
        static size_t num = 0;

        num++;
        return (num);
}

