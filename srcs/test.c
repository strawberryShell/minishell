#include "string.h"
#include "stdio.h"

int main(void)
{
    printf("%d\n", strcmp("quitquit", "quit"));
    printf("%d\n", strcmp("quita", "quit"));
}