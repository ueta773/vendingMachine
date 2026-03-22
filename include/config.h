#ifndef CONFIG_H
#define CONFIG_H

/* メインメニュー番号 */
typedef enum{
    MENU_NONE = 0,
    MENU_BUY = 1,
    MENU_MAINTENANCE = 2,
    MENU_EXIT = 99
} Menu;

/* メンテナンスメニュー番号 */
typedef enum{
    MAINT_NONE = 0,
    MAINT_ADD_PRODUCT = 1,
    MAINT_CHANGE_PRICE = 2,
    MAINT_ADD_STOCK = 3,
    MAINT_DELETE_PRODUCT = 4,
    MAINT_BACK = 99
} MaintenanceMenu;

enum{
    COIN_10 = 10,
    COIN_50 = 50,
    COIN_100 = 100,
    COIN_500 = 500
};

enum{
    MAX_COIN_COUNT = 100
};

// enum{
//     DRINK01_PRICE = 100,
//     DRINK02_PRICE = 120,
//     DRINK03_PRICE = 140
// };

enum{
    MIN_SYOUHIN_NUMBER = 1
};

#endif