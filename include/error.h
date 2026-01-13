#ifndef ERROR_H
#define ERROR_H

int read_int(const char *prompt, int *out);
int read_int_range(const char *prompt, int min, int max, int *out);

#endif