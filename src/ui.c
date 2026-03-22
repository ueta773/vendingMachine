#include "ui.h"
#include "product.h"
#include "error.h"
#include "ui_messages.h"
#include <stdio.h>

// メニュー選択
Menu select_menu(void)
{
    int inputMenu = MENU_BUY;

    printf(MSG_APP_TITLE);
    printf(MSG_MENU);

    if (!read_int(MSG_INPUT_NUMBER,&inputMenu)){
        printf(MSG_ERROR_NUMBER);
        return MENU_NONE;
    }

    if (inputMenu ==  MENU_BUY || inputMenu == MENU_MAINTENANCE || inputMenu == MENU_EXIT){
        return (Menu)inputMenu;
    }

    printf(MSG_ERROR_RANGE);
        return MENU_NONE;
}

// 商品一覧を表示
void show_products(void)
{
    printf(INFO_PRODUCT_LIST);

    if (productCount == 0){
        printf(INFO_NO_PRODUCTS);
        return;
    }

    for (int i = 0; i < productCount; i++){
        printf("%d：%s(%d円) 在庫:%d\n",
            products[i].id,
            products[i].name,
            products[i].price,
            products[i].stock);
    }
}

// 商品番号を入力
int select_products(int itemCount)
{
    int syouhinNumber;

    while (1){
        if(!read_int_range(PROMPT_SELECT_PRODUCT,MIN_SYOUHIN_NUMBER,itemCount,&syouhinNumber)){
            printf(ERROR_INVALID_PRODUCT);
            continue;
        }
        return syouhinNumber;
    }
}