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

// static Product products[MAX_PRODUCTS];
// static int productCount;

void load_products(Product products[],int *count);
void save_products(Product products[],int count);

// extern const char * const syouhinName[];
// extern const int prices[];
// extern const int itemCount;

#endif