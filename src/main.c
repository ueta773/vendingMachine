#include <stdio.h>
#include "config.h"
#include "ui.h"
#include "vending.h"

int main(void)
{
    while (1)
    {
        Menu menu = select_menu();

        switch (menu){
            case MENU_BUY:
                buy_flow();
                break;
            case MENU_MAINTENANCE:
                printf("%d:メンテナンス\n",menu);
                return 0;
                break;
            case MENU_EXIT:
                printf("%d:終了\n",menu);
                return 0;
            default:
                break;
        }
    }
}
