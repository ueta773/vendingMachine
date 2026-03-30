// #include "main_menu.h"
#include "config.h"
#include "ui.h"
#include "vending.h"
#include "product.h"
#include "maintenance.h"
#include <stdio.h>

int main(void){
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    load_products(products,&productCount);

    while (1){
        Menu menu = select_menu();

        switch (menu){
            case MENU_BUY:
                buy_flow(products,&productCount);
                break;
            case MENU_MAINTENANCE:
                maintenance_flow(products,&productCount);
                break;
            case MENU_EXIT:
                printf("%d:終了\n",menu);
                return 0;
            default:
                break;
        }
    }
}
