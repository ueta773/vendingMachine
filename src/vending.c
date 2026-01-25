#include "vending.h"
#include "ui.h"
#include "coin.h"
#include "product.h"
#include "error.h"
#include "ui_messages.h"
#include <stdio.h>

// 購入の処理
void buy_flow(void)
{
    show_products();

    int total = input_total_money();
    if (total == 0){
        printf(INFO_ZERO_MONEY);
        return;
    }

    int productNo = select_products(itemCount);
    int price = prices[productNo - 1];

    while (total < price){
        int lack = price - total;
        printf(INFO_LACK_MONEY,lack);
        printf(PROMPT_ADD_COINS);

        int add = input_total_money();
        total += add;
    }
    printf(INFO_PURCHASE_OK);
    printf(INFO_CHANGE,total - price);
}