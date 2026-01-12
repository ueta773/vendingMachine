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

int main()
{
    Menu menuNumber = MENU_NONE;
    int jyuuYen = 0;
    int gojyuuYen = 0;
    int hyakuYen = 0;
    int gohyakuYen = 0;
    int tounyuuKingaku = 0;
    int syouhinNumber = 0;
    int otsuri = 0;


    while (1)
    {
        printf("\n自動販売機プログラム\n");
        printf("【メニュー選択】%d：商品購入、%d：メンテナンス、%d：終了\n",MENU_BUY,MENU_MAINTENANCE,MENU_EXIT);

        int inputMenu = 0;
        if (!read_int("実行するメニュー番号を入力してください。\n",&inputMenu)){
            printf("Error::数値で入力してください。\n");
            continue;
        }

        if (inputMenu ==  MENU_BUY || inputMenu == MENU_MAINTENANCE || inputMenu == MENU_EXIT){
            menuNumber = (Menu)inputMenu;
        } else{
            printf("\n正しい番号を入力してください。\n");
            menuNumber = MENU_NONE;
            continue;
        }

        switch (menuNumber)
        {
            case MENU_BUY:
            {
                int syouhinPrice = 0;

                // 商品一覧
                printf("\n【取扱商品】\n");
                for (int i = 0; i < itemCount;i ++)
                {
                    printf("%d：%s(%d円)\n",i + MIN_SYOUHIN_NUMBER,syouhinName[i],prices[i]);
                }

                // 硬貨投入処理
                inputCoins(&jyuuYen,&gojyuuYen,&hyakuYen,&gohyakuYen);

                // 投入金額の合計
                tounyuuKingaku = (jyuuYen*COIN_10) + (gojyuuYen*COIN_50) + (hyakuYen*COIN_100) + (gohyakuYen*COIN_500);

                // 合計額が0の場合、メニューへ戻る
                if (tounyuuKingaku == 0)
                {
                    printf("\n投入金額が0のためメニューに戻ります。\n");
                    menuNumber = MENU_NONE;
                    break;
                }

                while (1)
                {
                    if(!read_int_range("\n購入する商品の番号を入力してください。\n",MIN_SYOUHIN_NUMBER,itemCount,&syouhinNumber))
                    {
                        printf("Error::存在しない商品番号です。もう一度入力してください。\n");
                        continue;
                    }
                    break;
                }

                syouhinPrice = prices[syouhinNumber - 1];

                // 投入金額と商品価格の比較
                if (tounyuuKingaku < syouhinPrice)
                {
                    int fusokuKingaku = 0;
                    fusokuKingaku = syouhinPrice - tounyuuKingaku;

                    // 投入金額が不足していた場合の処理
                    while (fusokuKingaku > 0)
                    {
                        printf("\n投入金額が%d円不足しています。\n商品価格：%d円、投入金額：%d円\n",fusokuKingaku,syouhinPrice,tounyuuKingaku);

                        // 追加で硬貨投入
                        printf("追加で硬貨を投入してください。\n");

                        // 硬貨投入処理
                        inputCoins(&jyuuYen,&gojyuuYen,&hyakuYen,&gohyakuYen);

                        tounyuuKingaku += (jyuuYen*COIN_10) +  (gojyuuYen*COIN_50) + (hyakuYen*COIN_100) + (gohyakuYen*COIN_500);
                        fusokuKingaku = syouhinPrice - tounyuuKingaku;
                    }
                }

                printf("\n【購入完了！】\n");

                // お釣りの計算
                otsuri = tounyuuKingaku - syouhinPrice;
                printf("おつり%d円\n",otsuri);

                menuNumber = MENU_NONE;
                break;
            }
            case MENU_MAINTENANCE:
                printf("%d:メンテナンス\n",menuNumber);
                return 0;
                break;

            case MENU_EXIT:
                printf("%d:終了\n",menuNumber);
                return 0;
                break;

            default:
                printf("正しい番号を入力してください。\n");
                break;
        }
    }
    return 0;
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