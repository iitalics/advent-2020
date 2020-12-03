#include <stdio.h>

int main()
{
        int lo, hi, i, n, m, valid1, valid2;
        char ch, reqch;

        valid1 = valid2 = 0;
        while (scanf("%d-%d %c: ", &lo, &hi, &reqch) != -1) {

                n = m = 0;
                for (i = 1; (ch = getchar()) != '\n'; i++) {
                        if (ch != reqch) {
                                continue;
                        }
                        n++;
                        if (i == lo || i == hi) {
                                m++;
                        }
                }

                valid1 += (n >= lo && n <= hi);
                valid2 += (m == 1);
        }

        printf("%d, %d\n", valid1, valid2);
        return 0;
}
