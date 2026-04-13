#include "vending.h"
#include "ui.h"
#include "coin.h"
#include "product.h"
#include "error.h"
#include "ui_messages.h"
#include <stdio.h>

// 購入の処理
void buy_flow(Product products[],int *count)
{
    if (*count == 0){
        printf(INFO_NO_PRODUCTS);
        return;
    }

    show_products(products,*count);

    int total = input_total_money();
    if (total == 0){
        printf(INFO_ZERO_MONEY);
        return;
    }

    int productNo = select_products(*count);
    Product *product = &products[productNo - 1];

    if (product->stock <= 0){
        printf(ERROR_OUT_OF_STOCK);
        return;
    }

    while (total < product->price){
        int lack = product->price - total;
        printf(INFO_LACK_MONEY,lack);
        printf(PROMPT_ADD_COINS);

        int add = input_total_money();
        total += add;
    }

    product->stock--;
    save_products(products,*count);

    printf(INFO_PURCHASE_OK);
    printf(INFO_CHANGE,total - product->price);
}