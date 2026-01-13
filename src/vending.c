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
        printf(MSG_ZERO_MONEY);
        return;
    }

    int productNo = select_products(itemCount);
    int price = prices[productNo - 1];

    while (total < price){
        int lack = price - total;
        printf(MSG_LACK_MONEY,lack);
        printf(MSG_ADD_COINS);

        int add = input_total_money();
        total += add;
    }
    printf(MSG_PURCHASE_OK);
    printf(MSG_CHANGE,total - price);
}