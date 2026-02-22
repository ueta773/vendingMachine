#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#define ERROR_TAG "Error::"

#define MSG_APP_TITLE       "自動販売機プログラム\n"
#define MSG_INPUT_NUMBER    "実行するメニュー番号を入力してください。\n"
#define MSG_ERROR_NUMBER    ERROR_TAG "数値を入力してください。\n"
#define MSG_ERROR_RANGE     ERROR_TAG "正しい番号を入力してください。\n"

// メニュー選択時
#define MSG_MENU \
"【メニュー選択】\n" \
"1：商品購入\n" \
"2：メンテナンス\n" \
"99：終了\n"

// 商品選択時
#define INFO_PRODUCT_LIST    "【取扱商品】\n"
#define PROMPT_SELECT_PRODUCT  "購入する商品の番号を入力してください。\n"
#define ERROR_INVALID_PRODUCT ERROR_TAG "存在しない商品番号です。もう一度入力してください。\n"

// 硬貨投入時
#define PROMPT_MSG_COIN_10   "10円硬貨の枚数を入力してください。\n"
#define PROMPT_MSG_COIN_50   "50円硬貨の枚数を入力してください。\n"
#define PROMPT_MSG_COIN_100  "100円硬貨の枚数を入力してください。\n"
#define PROMPT_MSG_COIN_500  "500円硬貨の枚数を入力してください。\n"
#define ERROR_COIN_COUNT  ERROR_TAG "0~100の数値を入力してください。\n"

// 購入の処理時
#define INFO_ZERO_MONEY    "投入金額が0のためメニューに戻ります。\n"
#define INFO_LACK_MONEY    "投入金額が%d円不足しています。\n"
#define PROMPT_ADD_COINS    "追加で硬貨を投入してください。\n"
#define INFO_PURCHASE_OK  "【購入完了！】\n"
#define INFO_CHANGE       "おつり%d円\n"

#endif