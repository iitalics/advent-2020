#include <stdio.h>

#define N 2020
static char S[N + 1] = {0};

int main()
{
        int i, j, k;

        while (scanf("%d\n", &i) > 0) {
                if (S[N - i]) {
                        printf("%d", i * (N - i));
                }

                for (j = 0; j <= N - i; j++) {
                        k = N - i - j;
                        if (S[j] && S[k]) {
                                printf(", %d\n", i * j * k);
                                break;
                        }
                }

                S[i] = 1;
        }

        return 0;
}
