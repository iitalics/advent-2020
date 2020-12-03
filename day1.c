#include <stdio.h>

static int seen[2021] = {0};

int main()
{
    int entry, other;

    for (;;) {
        scanf("%d\n", &entry);
        other = 2020 - entry;
        if (seen[other]) {
            printf("%d\n", entry * other);
            break;
        }
        seen[entry] = 1;
    }

    return 0;
}
