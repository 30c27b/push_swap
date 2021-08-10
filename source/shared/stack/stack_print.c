#include "shared.h"
#include "carbon/fmt.h"
#include <stddef.h>
#include <stdio.h>

void stack_print(t_stack *st_a, t_stack *st_b)
{
	printf("stack A (%zu):\n>", st_a->len);
	for (size_t i = 0; i < st_a->len; i++)
	{
		printf(" %lld", st_a->data[i]);
	}
	printf("\n");
	printf("stack B (%zu):\n>", st_b->len);
	for (size_t i = 0; i < st_b->len; i++)
	{
		printf(" %lld", st_b->data[i]);
	}
	printf("\n");
}
