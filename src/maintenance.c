// #include "main_menu.h"
#include "product.h"
#include "ui.h"
#include "error.h"
#include "ui_messages.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

// 商品追加
static void add_product(Product products[],int *count)
{
    // 商品一覧
    show_products(products,*count);

    if (*count >= MAX_PRODUCTS){
        printf(ERROR_PRODUCT_LIMIT);
        return;
    }

    Product *product = &products[*count];
    product->id = (*count) + 1;

    // 追加する商品名の入力を受ける
    input_string(PROMPT_PRODUCT_NAME,
                product->name,
                sizeof(product->name));

    // 追加する商品の価格の入力を受ける
    // input_int(PROMPT_PRODUCT_PRICE,
    //             0, 1000,
    //             &product->price);

    // 追加する商品の在庫の入力を受ける
    // input_int(PROMPT_PRODUCT_STOCK,
    //             0, 10,
    //             &product->stock);

    // // 追加する商品名の入力を受ける
    // printf(PROMPT_PRODUCT_NAME);
    // // fflush(stdout);

    // fgets(product->name,sizeof(product->name),stdin);
    // product->name[strcspn(product->name,"\n")] = 0;

    // // 追加する商品の価格の入力を受ける
    while (!read_int_range(PROMPT_PRODUCT_PRICE,0,1000,&product->price)){
        printf(ERROR_PRODUCT_PRICE);
    };

    // // 追加する商品の在庫の入力を受ける
    while (!read_int_range(PROMPT_PRODUCT_STOCK,0,10,&product->stock)){
        printf(ERROR_PRODUCT_STOCK);
    };

    (*count)++;
    save_products(products,*count);
    printf(INFO_PRODUCT_ADDED);

    // 追加後の商品一覧
    show_products(products,*count);
}

// 価格変更
static void change_price(Product products[],int *count)
{
    if(*count == 0){
        printf(INFO_NO_PRODUCTS);
        return;
    }

    // 商品一覧
    show_products(products,*count);

    // 価格変更を行いたい商品番号の入力を受ける
    int number;
    while (!read_int_range(PROMPT_CHANGE_ID,1,*count,&number)){
        printf(MSG_ERROR_RANGE);
    }

    // 価格変更
    int price;
    while (!read_int_range(PROMPT_NEW_PRICE,0,1000,&price)){
        printf(ERROR_PRODUCT_PRICE);
    }

    products[number-1].price = price;
    save_products(products,*count);
    printf(INFO_PRICE_CHANGED);
    show_products(products,*count);
}

// 在庫補充
static void add_stock(Product products[],int *count)
{
        if(*count == 0){
        printf(INFO_NO_PRODUCTS);
        return;
    }

    // 商品一覧
    show_products(products,*count);

    // 在庫補充したい商品番号の入力を受ける
    int number;
    while (!read_int_range(PROMPT_STOCK_ID,1,*count,&number)){
        printf(ERROR_INVALID_PRODUCT);
    }

    Product *product = &products[number-1];

    // 在庫の合計が10を超える場合、エラー
    if (product->stock >= 10){
        printf(ERROR_STOCK_OVER);
        return;
    }

    // 在庫補充の数の入力を受ける
    int add;
    while (!read_int_range(PROMPT_ADD_STOCK,0,10,&add)){
        printf(ERROR_PRODUCT_STOCK);
    }

    // 在庫の合計が10を超える場合、エラー
    if (product->stock + add > 10){
        printf(ERROR_STOCK_OVER);
        return;
    }

    product->stock += add;
    save_products(products,*count);
    printf(INFO_STOCK_ADDED);
    // 在庫補充後の商品一覧
    show_products(products,*count);
}

// 商品削除
static void delete_product(Product products[],int *count)
{
        if(*count == 0){
        printf(INFO_NO_PRODUCTS);
        return;
    }

    // 商品一覧
    show_products(products,*count);

    // 削除する商品の番号の入力を受ける
    int number;
    while (!read_int_range(PROMPT_DELETE_ID,1,*count,&number)){
        printf(ERROR_INVALID_PRODUCT);
    }

    for (int i = number-1; i < *count-1; i++){
        products[i] = products[i+1];
    }

    (*count)--;

    // 商品番号を振り直す
    for (int i = 0; i < *count; i++){
        products[i].id = i + 1;
    }

    save_products(products,*count);

    printf(INFO_PRODUCT_DELETED);
    // 商品削除後の商品一覧
    show_products(products,*count);
}

void maintenance_flow(Product products[],int *count)
{
    int menu;

    while (1){
        printf(MSG_MAINT_TITLE);

        if (!read_int(PROMPT_MAINT_NUMBER,&menu)){
            printf(MSG_ERROR_NUMBER);
            continue;
        }

        switch (menu){
            case MAINT_ADD_PRODUCT:
                add_product(products,count);
                break;
            case MAINT_CHANGE_PRICE:
                change_price(products,count);
                break;
            case MAINT_ADD_STOCK:
                add_stock(products,count);
                break;
            case MAINT_DELETE_PRODUCT:
                delete_product(products,count);
                break;
            case MAINT_BACK:
                return;
            default: printf(ERROR_INVALID_MENU);
        }
    }
}
