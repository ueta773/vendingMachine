#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_string(const char *prompt, char *buf, int size)
{
    while (1) {
        printf("%s", prompt);

        if (!fgets(buf, size, stdin))
            continue;

        buf[strcspn(buf, "\n")] = 0;

        if (strlen(buf) == 0)
            continue;

        return;
    }
}

int input_int(const char *prompt, int min, int max, int *out)
{
    char buf[64];

    while (1) {
        printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin))
            continue;

        char *end;
        long val = strtol(buf, &end, 10);

        if (end == buf)
            continue;

        if (val < min || val > max)
            continue;

        *out = (int)val;
        return 1;
    }
}