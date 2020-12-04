#include <stdio.h>
#include <string.h>

#define KEY    0
#define VALUE  1
#define SPACE  2

#define BYR (1 << 0)
#define IYR (1 << 1)
#define EYR (1 << 2)
#define HGT (1 << 3)
#define HCL (1 << 4)
#define ECL (1 << 5)
#define PID (1 << 6)
#define CID (1 << 7)

#define REQUIRED (BYR | IYR | EYR | HGT | HCL | ECL | PID/* | CID */)

static int st;
static int mask;
static int count;

static char keyname[4];
static int keymask;
static char *keyptr;

static void begin_key(void)
{
        keyptr = keyname;
        st = KEY;
}

static void end_key(void)
{
        *keyptr = '\0';
        if (strcmp(keyname, "byr") == 0) { keymask = BYR; }
        if (strcmp(keyname, "iyr") == 0) { keymask = IYR; }
        if (strcmp(keyname, "eyr") == 0) { keymask = EYR; }
        if (strcmp(keyname, "hgt") == 0) { keymask = HGT; }
        if (strcmp(keyname, "hcl") == 0) { keymask = HCL; }
        if (strcmp(keyname, "ecl") == 0) { keymask = ECL; }
        if (strcmp(keyname, "pid") == 0) { keymask = PID; }
        if (strcmp(keyname, "cid") == 0) { keymask = CID; }
        st = VALUE;
}

static void key(char ch)
{
        switch (ch) {
        case ':':
                end_key();
                break;

        default:
                *keyptr++ = ch;
                break;
        }
}

static void value(char ch)
{
        switch (ch) {
        case ' ':
        case '\n':
                mask &= ~keymask;
                st = SPACE;
                return;

        default:
                break;
        }
}

static void begin_passport(void)
{
        mask = REQUIRED;
        begin_key();
}

static void end_passport(void)
{
        if (mask == 0) {
                count++;
        }
}

static void space(char ch)
{
        switch (ch) {
        case '\n':
                end_passport();
                begin_passport();
                break;

        default:
                begin_key();
                key(ch);
                break;
        }
}

int main()
{
        char ch;

        count = 0;

        begin_passport();
        while ((ch = getchar()) != EOF) {
                switch (st) {
                case KEY:   key(ch);   break;
                case VALUE: value(ch); break;
                case SPACE: space(ch); break;
                default: break;
                }
        }
        end_passport();

        printf("%d\n", count);
        return 0;
}
