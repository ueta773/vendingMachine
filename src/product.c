#include "product.h"
#include "config.h"
#include "ui_messages.h"
#include <stdio.h>
#include <string.h>

// static Product products[MAX_PRODUCTS];
// static int productCount = 0;

#define FILE_NAME "products.txt"

void load_products(Product products[],int *count){
    *count = 0;
    FILE *fp = fopen(FILE_NAME,"r");
    if (!fp) return;

    char line[256];

    while (fgets(line, sizeof(line), fp)){

        Product p;

        if (sscanf(line,"%d,%[^,],%d,%d",
            &p.id,
            p.name,
            &p.price,
            &p.stock) == 4){

            if(*count >= MAX_PRODUCTS) break;
            products[(*count)++]= p;
            }
    }

    // while (fscanf(fp,"%d,%20[^,],%d,%d",
    //     &products[productCount].id,
    //     products[productCount].name,
    //     &products[productCount].price,
    //     &products[productCount].stock) == 4){
    //         productCount ++;
    // }
    fclose(fp);
}

void save_products(Product products[],int count){
    FILE *fp = fopen(FILE_NAME,"w");
    if (!fp){
        printf(ERROR_SAVE_FAILED);
        return;
    }

    for (int i=0; i < count ; i++){
        fprintf(fp,"%d,%s,%d,%d\n",
            products[i].id,
            products[i].name,
            products[i].price,
            products[i].stock);
    }

    fclose(fp);
    printf(INFO_SAVE_OK);
}

// const char * const syouhinName[] = {"お茶","コーヒー","ジュース"};
// const int prices[] = {DRINK01_PRICE,DRINK02_PRICE,DRINK03_PRICE};
// const int itemCount = 3;
