#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 20

/* 商品データ */
typedef struct{
    int id;
    char name[MAX_NAME_LEN+1];
    int price;
    int stock;
} Product;

extern Product products[MAX_PRODUCTS];
extern int productCount;

void load_products(void);
void save_products(void);

// extern const char * const syouhinName[];
// extern const int prices[];
// extern const int itemCount;

#endif