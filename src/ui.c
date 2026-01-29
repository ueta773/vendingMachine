#include "ui.h"
#include "product.h"
#include "error.h"
#include <stdio.h>

// メニュー選択
Menu select_menu(void)
{
    int inputMenu = MENU_BUY;

    printf("自動販売機プログラム\n");
    printf("【メニュー選択】%d：商品購入、%d：メンテナンス、%d：終了\n",MENU_BUY,MENU_MAINTENANCE,MENU_EXIT);

    if (!read_int("実行するメニュー番号を入力してください。\n",&inputMenu)){
        printf("Error::数値で入力してください。\n");
        return MENU_NONE;
    }

    if (inputMenu ==  MENU_BUY || inputMenu == MENU_MAINTENANCE || inputMenu == MENU_EXIT){
        return (Menu)inputMenu;
    }

    printf("正しい番号を入力してください。\n");
        return MENU_NONE;
}

// 商品一覧を表示
void show_products(void)
{
    printf("【取扱商品】\n");
    for (int i = 0; i < itemCount;i ++){
        printf("%d：%s(%d円)\n",i + MIN_SYOUHIN_NUMBER,syouhinName[i],prices[i]);
    }
}

// 商品番号を入力
int select_products(int itemCount)
{
    int syouhinNumber;

    while (1){
        if(!read_int_range("購入する商品の番号を入力してください。\n",MIN_SYOUHIN_NUMBER,itemCount,&syouhinNumber)){
            printf("Error::存在しない商品番号です。もう一度入力してください。\n");
            continue;
        }
        return syouhinNumber;
    }
}