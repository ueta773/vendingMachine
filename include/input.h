#ifndef INPUT_H
#define INPUT_H

int input_int(const char *prompt, int min, int max, int *out);
void input_string(const char *prompt, char *buf, int size);

#endif