#include "coin.h"
#include "config.h"
#include "error.h"
#include <limits.h>
#include <stdio.h>

// 硬貨投入処理
void inputCoins(int *jyuu,int *gojyuu, int *hyaku,int *gohyaku){
    while (!read_int_range("\n10円硬貨の投入する枚数を入力してください。\n",0, INT_MAX, jyuu)){
        printf("Error::0以上の数値を入力してください。");
    }
    while (!read_int_range("\n50円硬貨の投入する枚数を入力してください。\n",0, INT_MAX, gojyuu)){
        printf("Error::0以上の数値を入力してください。");
    }
    while (!read_int_range("\n100円硬貨の投入する枚数を入力してください。\n",0, INT_MAX, hyaku)){
        printf("Error::0以上の数値を入力してください。");
    }
    while (!read_int_range("\n500円硬貨の投入する枚数を入力してください。\n",0, INT_MAX, gohyaku)){
        printf("Error::0以上の数値を入力してください。");
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