#include <stdio.h>

int main()
{
    int x, y, w, even;
    long long int t11, t31, t51, t71, t12;
    char ch;

    y = x = 0;
    even = w = 1;
    t11 = t31 = t51 = t71 = t12 = 0;

    while ((ch = getchar()) != EOF) {
        switch (ch) {
        case '\n':
            w = x;
            x = 0;
            y++;
            even = !even;
            break;

        case '#':
            if (x == y       % w) t11++;
            if (x == (y * 3) % w) t31++;
            if (x == (y * 5) % w) t51++;
            if (x == (y * 7) % w) t71++;
            if (x == (y / 2) % w && even) t12++;

        default:
            x++;
            break;
        }
    }

    printf("%lld, %lld\n", t31, (t11 * t31 * t51 * t71 * t12));
    return 0;
}
