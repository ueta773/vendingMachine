#include "coin.h"
#include "config.h"
#include "error.h"
#include "ui_messages.h"
#include <limits.h>
#include <stdio.h>

// 硬貨投入処理
void inputCoins(int *jyuu,int *gojyuu, int *hyaku,int *gohyaku){
    while (!read_int_range(MSG_COIN_10, 0, INT_MAX, jyuu)){
        printf(MSG_COIN_ERR);
    }
    while (!read_int_range(MSG_COIN_50, 0, INT_MAX, gojyuu)){
        printf(MSG_COIN_ERR);
    }
    while (!read_int_range(MSG_COIN_100, 0, INT_MAX, hyaku)){
        printf(MSG_COIN_ERR);
    }
    while (!read_int_range(MSG_COIN_500, 0, INT_MAX, gohyaku)){
        printf(MSG_COIN_ERR);
    }
}

// 合計金額
int input_total_money(void)
{
    int coin10Count = 0;
    int coin50Count = 0;
    int coin100Count = 0;
    int coin500Count = 0;

    inputCoins(&coin10Count, &coin50Count, &coin100Count, &coin500Count);

    return ((coin10Count * COIN_10) + (coin50Count * COIN_50) + (coin100Count * COIN_100) + (coin500Count * COIN_500));
}