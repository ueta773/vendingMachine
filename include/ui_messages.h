#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#define ERROR_TAG "Error::"

#define MSG_APP_TITLE       "自動販売機プログラム\n"
#define MSG_INPUT_NUMBER    "実行するメニュー番号を入力してください。\n"
#define MSG_ERROR_NUMBER    ERROR_TAG "半角数字を入力してください。\n"
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
#define ERROR_OUT_OF_STOCK ERROR_TAG "在庫切れです\n"
#define INFO_NO_PRODUCTS "登録商品がありません\n"

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

// メンテナンス機能の商品登録
#define MSG_MAINT_TITLE \
"【メンテナンスメニュー】\n"\
"1：商品追加\n"\
"2：商品価格変更\n"\
"3：在庫補充\n"\
"4：商品削除\n"\
"99：メインメニューへ戻る\n"

#define PROMPT_MAINT_NUMBER "番号を入力してください。\n"
#define ERROR_INVALID_MENU    ERROR_TAG "無効な番号です。\n"

// 商品追加
#define PROMPT_PRODUCT_NAME   "追加する商品名を入力してください。\n"
#define PROMPT_PRODUCT_PRICE  "価格(1〜1000円)を入力してください。\n"
#define ERROR_PRODUCT_PRICE   ERROR_TAG "1~1000の価格を入力してください。\n"
#define PROMPT_PRODUCT_STOCK  "初期在庫(0〜10)を入力してください。\n"
#define ERROR_PRODUCT_STOCK   ERROR_TAG "0~10の数値を入力してください。\n"
#define ERROR_PRODUCT_LIMIT   ERROR_TAG "これ以上登録できません。\n"
#define INFO_PRODUCT_ADDED    "商品を登録しました。\n"

// 価格変更
#define PROMPT_CHANGE_ID      "価格変更を行いたい商品番号を入力してください。\n"
#define PROMPT_NEW_PRICE      "新しい価格(1〜1000円)を入力してください。\n"
#define INFO_PRICE_CHANGED    "価格を変更しました。\n"

// 在庫補充
#define PROMPT_STOCK_ID       "在庫補充を行う商品番号を入力してください。\n"
#define PROMPT_ADD_STOCK      "追加する在庫数を入力してください。(合計在庫数の上限：10)\n"
#define ERROR_STOCK_OVER      ERROR_TAG "在庫上限(10)を超えます。\n"
#define INFO_STOCK_ADDED      "在庫を補充しました。\n"

// 商品削除
#define INFO_PRODUCT_DELETED "商品を削除しました。\n"
#define PROMPT_DELETE_ID "削除する商品番号を入力してください。\n"

// 商品削除

// ファイル処理
#define INFO_SAVE_OK          "保存しました。\n"
#define ERROR_SAVE_FAILED     ERROR_TAG "保存に失敗しました\n"

#endif