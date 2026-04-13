#ifndef UI_H
#define UI_H

#include "config.h"
#include "product.h"

Menu select_menu(void);
void show_products(Product products[],int count);

int select_products(int itemCount);

#endif