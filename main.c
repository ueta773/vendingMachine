#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/* メニュー番号(将来的にヘッダーファイルへ移行) */
typedef enum{
    MENU_NONE = 0,
    MENU_BUY = 1,
    MENU_MAINTENANCE = 2,
    MENU_EXIT = 99
} Menu;

/* (将来的にヘッダーファイルへ移行) */
extern const int COIN_10;
extern const int COIN_50;
extern const int COIN_100;
extern const int COIN_500;

/* 商品価格(将来的にヘッダーファイルへ移行) */
extern const int DRINK01_PRICE;
extern const int DRINK02_PRICE;
extern const int DRINK03_PRICE;

/* extern constの定義(実体) */
const int COIN_10 = 10;
const int COIN_50 = 50;
const int COIN_100 = 100;
const int COIN_500 = 500;

const int DRINK01_PRICE = 100;
const int DRINK02_PRICE = 120;
const int DRINK03_PRICE = 140;

static const int MIN_SYOUHIN_NUMBER = 1;

/* 商品データ */
static const char * const syouhinName[] = {"お茶","コーヒー","ジュース"};
static const int prices[] = {DRINK01_PRICE,DRINK02_PRICE,DRINK03_PRICE};
static const int itemCount = (int)(sizeof(prices) / sizeof(prices[0]));

void inputCoins(int *jyuu,int *gojyuu, int *hyaku,int *gohyaku);

// 1行分の入力を読み取り、intへ変換。成功：1、失敗：0を返す。
static int read_int(const char *prompt, int *out)
{
    char buf[64];

    if (prompt){
        printf("%s",prompt);
    }

    if (!fgets(buf, sizeof(buf),stdin)){
        return 0;
    }
    
    errno = 0;
    char *end = NULL;
    long v = strtol(buf, &end, 10);

    // オーバーフローや変換エラーがあれば失敗
    if(errno != 0) return 0;
    // 先頭から1文字も数値に変換できなかった場合("abc"など。)
    if(end == buf) return 0;
    // 数値の後の空白・タブをスキップする
    while (*end == ' ' || *end == '\t') end++;
    // 改行や文字列終端以外が残っていればエラー
    if(*end != '\n' && *end != '\0') return 0;
    // longの値がintの範囲に収まっているかを確認
    if(v < INT_MIN || v > INT_MAX) return 0;

    // 問題がなければintに変換
    *out = (int)v;
    return 1;
}

// read_int に範囲チェックを追加
static int read_int_range(const char *prompt, int min, int max, int *out)
{
    int v;
    // 数値として正しく読めるかを確認
    if(!read_int(prompt, &v)) return 0;
    // 指定した範囲に入っているかを確認
    if(v < min || v > max) return 0;
    *out = v;
    return 1;
}

Menu select_menu(void);
void show_products(void);
int select_products(int itemCount);
int input_total_money(void);
void buy_flow(void);

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

// メニュー選択
Menu select_menu(void)
{
    int inputMenu = MENU_BUY;

    printf("\n自動販売機プログラム\n");
    printf("【メニュー選択】%d：商品購入、%d：メンテナンス、%d：終了\n",MENU_BUY,MENU_MAINTENANCE,MENU_EXIT);

    if (!read_int("実行するメニュー番号を入力してください。\n",&inputMenu)){
        printf("Error::数値で入力してください。\n");
        return MENU_NONE;
    }

    if (inputMenu ==  MENU_BUY || inputMenu == MENU_MAINTENANCE || inputMenu == MENU_EXIT){
        return (Menu)inputMenu;
    }

    printf("\n正しい番号を入力してください。\n");
        return MENU_NONE;
}

// 商品一覧を表示
void show_products(void)
{
    printf("\n【取扱商品】\n");
    for (int i = 0; i < itemCount;i ++){
        printf("%d：%s(%d円)\n",i + MIN_SYOUHIN_NUMBER,syouhinName[i],prices[i]);
    }
}

// 商品番号を入力
int select_products(int itemCount)
{
    int syouhinNumber;

    while (1){
        if(!read_int_range("\n購入する商品の番号を入力してください。\n",MIN_SYOUHIN_NUMBER,itemCount,&syouhinNumber)){
            printf("Error::存在しない商品番号です。もう一度入力してください。\n");
            continue;
        }
        return syouhinNumber;
    }
}

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

// 購入の処理
void buy_flow(void)
{
    show_products();

    int total = input_total_money();
    if (total = 0){
        printf("\n投入金額が0のためメニューに戻ります。\n");
        return;
    }

    int productNo = select_products(itemCount);
    int price = prices[productNo - 1];

    while (total < price){
        int lack = price - total;
        printf("\n投入金額が%d円不足しています。\n",lack);
        printf("追加で硬貨を投入してください。\n");

        int add = input_total_money();
        total += add;
    }
    printf("\n【購入完了！】\n");
    printf("おつり%d円\n",total - price);
}