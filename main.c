#include <stdio.h>

#define COIN_10 10
#define COIN_50 50
#define COIN_100 100
#define COIN_500 500
#define INITIAL_VALUE 0
#define PRICE_OCHA 100
#define PRICE_COFFEE 120
#define PRICE_JUICE 140
#define NENU_BUY 1
#define NENU_MAINTENANCE 2
#define NENU_EXIT 99
#define MIN_SYOUHIN_NUMBER 1
#define INFINITE_LOOP 1

void inputCoins(int *jyuu,int *gojyuu, int *hyaku,int *gohyaku);

int main()
{
    int menuNumber = INITIAL_VALUE;
    int jyuuYen = INITIAL_VALUE;
    int gojyuuYen = INITIAL_VALUE;
    int hyakuYen = INITIAL_VALUE;
    int gohyakuYen = INITIAL_VALUE;
    int tounyuuKingaku = INITIAL_VALUE;
    int syouhinNumber = INITIAL_VALUE;
    const char *syouhinName[] = {"お茶","コーヒー","ジュース"};
    int prices[] = {PRICE_OCHA,PRICE_COFFEE,PRICE_JUICE};
    int itemCount = 3;
    int otsuri = INITIAL_VALUE;


    while (menuNumber != NENU_BUY && menuNumber != NENU_MAINTENANCE && menuNumber != NENU_EXIT)
    {
        printf("\n自動販売機プログラム\n");
        // printf("【メニュー選択】実行するメニュー番号を入力してください。\n");
        printf("【メニュー選択】%d：商品購入、%d：メンテナンス、%d：終了\n",NENU_BUY,NENU_MAINTENANCE,NENU_EXIT);

        if (scanf("%d",&menuNumber) != 1)
        {
            printf("実行するメニュー番号を入力してください。\n");
            while (getchar() != '\n');
            continue;
        }
        switch (menuNumber)
        {
            case NENU_BUY:
            {
                int syouhinPrice = INITIAL_VALUE;

                // 商品一覧
                printf("\n【取扱商品】\n");
                for (int i = INITIAL_VALUE; i < itemCount;i ++)
                {
                    printf("%d：%s(%d円)\n",i + MIN_SYOUHIN_NUMBER,syouhinName[i],prices[i]);
                }

                // 硬貨投入処理
                inputCoins(&jyuuYen,&gojyuuYen,&hyakuYen,&gohyakuYen);

                // 投入金額の合計
                tounyuuKingaku = (jyuuYen*COIN_10) + (gojyuuYen*COIN_50) + (hyakuYen*COIN_100) + (gohyakuYen*COIN_500);

                // 合計額が0の場合、メニューへ戻る
                if (tounyuuKingaku == INITIAL_VALUE)
                {
                    printf("\n投入金額が0のためメニューに戻ります。\n");
                    menuNumber = INITIAL_VALUE;
                    break;
                }

                while (INFINITE_LOOP)
                {
                    printf("\n購入する商品の番号を入力してください。\n");
                    scanf("%d",&syouhinNumber);

                    // 正しい入力を受けるとループを抜ける。
                    if (syouhinNumber >= MIN_SYOUHIN_NUMBER && syouhinNumber <= itemCount)
                    {
                        break;
                    }

                    printf("Error::存在しない商品番号です。もう一度入力してください。\n");
                }

                syouhinPrice = prices[syouhinNumber - 1];

                // 投入金額と商品価格の比較
                if (tounyuuKingaku < syouhinPrice)
                {
                    int fusokuKingaku = INITIAL_VALUE;
                    fusokuKingaku = syouhinPrice - tounyuuKingaku;

                    // 投入金額が不足していた場合の処理
                    while (fusokuKingaku > INITIAL_VALUE)
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

                menuNumber = INITIAL_VALUE;
                break;
            }
            case NENU_MAINTENANCE:
                printf("%d:メンテナンス\n",menuNumber);
                break;

            case NENU_EXIT:
                printf("%d:終了\n",menuNumber);
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
    printf("\n10円硬貨の投入する枚数を入力してください。\n");
    scanf("%d",jyuu);
    printf("50円硬貨の投入する枚数を入力してください。\n");
    scanf("%d",gojyuu);
    printf("100円硬貨の投入する枚数を入力してください。\n");
    scanf("%d",hyaku);
    printf("500円硬貨の投入する枚数を入力してください。\n");
    scanf("%d",gohyaku);
}