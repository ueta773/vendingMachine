#include "vending.h"
#include "ui.h"
#include "coin.h"
#include "product.h"
#include "error.h"
#include <stdio.h>

// 購入の処理
void buy_flow(void)
{
    show_products();

    int total = input_total_money();
    if (total == 0){
        printf("\n投入金額が0のためメニューに戻ります。\n");
        return;
    }

    int productNo = select_products(itemCount);
    int price = prices[productNo - 1];

    while (total < price){
        int lack = price - total;
        printf("\n投入金額が%d円不足しています。\n",lack);
        printf("追加で硬貨を投入してください。\n");

        int add = input_total_money();
        total += add;
    }
    printf("\n【購入完了！】\n");
    printf("おつり%d円\n",total - price);
}