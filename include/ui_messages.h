#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#define MSG_APP_TITLE       "\n自動販売機プログラム\n"
#define MSG_INPUT_NUMBER    "実行するメニュー番号を入力してください。\n"
#define MSG_ERROR_NUMBER    "Error::数値を入力してください。\n"
#define MSG_ERROR_RANGE     "Error::正しい番号を入力してください。\n"

// メニュー選択時
#define MSG_MENU \
"【メニュー選択】\n" \
"1：商品購入\n" \
"2：メンテナンス\n" \
"99：終了\n"

// 商品選択時
#define MSG_PRODUCT_LIST    "\n【取扱商品】\n"
#define MSG_SELECT_PRODUCT  "\n購入する商品の番号を入力してください。\n"
#define MSG_INVALID_PRODUCT "Error::存在しない商品番号です。もう一度入力してください。\n"

// 硬貨投入時
#define MSG_COIN_10   "\n10円硬貨の枚数を入力してください。\n"
#define MSG_COIN_50   "\n50円硬貨の枚数を入力してください。\n"
#define MSG_COIN_100  "\n100円硬貨の枚数を入力してください。\n"
#define MSG_COIN_500  "\n500円硬貨の枚数を入力してください。\n"
#define MSG_COIN_ERR  "Error::0以上の数値を入力してください。\n"

// 購入の処理時
#define MSG_ZERO_MONEY    "\n投入金額が0のためメニューに戻ります。\n"
#define MSG_LACK_MONEY    "\n投入金額が%d円不足しています。\n"
#define MSG_ADD_COINS    "追加で硬貨を投入してください。\n"
#define MSG_PURCHASE_OK  "\n【購入完了！】\n"
#define MSG_CHANGE       "おつり%d円\n"

#endif