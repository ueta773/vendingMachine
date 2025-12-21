#include <stdio.h>

void inputCoins(int *jyuu,int *gojyuu, int *hyaku,int *gohyaku);

int main()
{
    int menuNumber = 0;
    int jyuuYen = 0;
    int gojyuuYen = 0;
    int hyakuYen = 0;
    int gohyakuYen = 0;
    int tounyuuKingaku = 0;
    int syouhinNumber = 0;
    const char *syouhinName[] = {"お茶","コーヒー","ジュース"};
    int prices[] = {100,120,140};
    int itemCount = 3;
    int otsuri = 0;


    while (menuNumber != 1 && menuNumber != 2 && menuNumber != 99)
    {
        printf("\n自動販売機プログラム\n");
        // printf("【メニュー選択】実行するメニュー番号を入力してください。\n");
        printf("【メニュー選択】1：商品購入、2：メンテナンス、99：終了\n");

        if (scanf("%d",&menuNumber) != 1)
        {
            printf("実行するメニュー番号を入力してください。\n");
            while (getchar() != '\n');
            continue;
        }
        switch (menuNumber)
        {
            case 1:
            {
                int syouhinPrice = 0;

                // 商品一覧
                printf("\n【取扱商品】\n");
                for (int i = 0; i < itemCount;i ++)
                {
                    printf("%d：%s(%d円)\n",i + 1,syouhinName[i],prices[i]);
                }

                // 硬貨投入処理
                inputCoins(&jyuuYen,&gojyuuYen,&hyakuYen,&gohyakuYen);

                // 投入金額の合計
                tounyuuKingaku = (jyuuYen*10) + (gojyuuYen*50) + (hyakuYen*100) + (gohyakuYen*500);

                // 合計額が0の場合、メニューへ戻る
                if (tounyuuKingaku == 0)
                {
                    printf("\n投入金額が0のためメニューに戻ります。\n");
                    menuNumber = 0;
                    break;
                }

                while (1)
                {
                    printf("\n購入する商品の番号を入力してください。\n");
                    scanf("%d",&syouhinNumber);

                    // 正しい入力を受けるとループを抜ける。
                    if (syouhinNumber >= 1 && syouhinNumber <= itemCount)
                    {
                        break;
                    }

                    printf("Error::存在しない商品番号です。もう一度入力してください。\n");
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

                        tounyuuKingaku += (jyuuYen*10) +  (gojyuuYen*50) + (hyakuYen*100) + (gohyakuYen*500);
                        fusokuKingaku = syouhinPrice - tounyuuKingaku;
                    }
                }

                printf("\n【購入完了！】\n");

                // お釣りの計算
                otsuri = tounyuuKingaku - syouhinPrice;
                printf("おつり%d円\n",otsuri);

                menuNumber = 0;
                break;
            }
            case 2:
                printf("%d:メンテナンス\n",menuNumber);
                break;

            case 99:
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