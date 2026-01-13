#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// 1行分の入力を読み取り、intへ変換。成功：1、失敗：0を返す。
int read_int(const char *prompt, int *out)
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
int read_int_range(const char *prompt, int min, int max, int *out)
{
    int v;
    // 数値として正しく読めるかを確認
    if(!read_int(prompt, &v)) return 0;
    // 指定した範囲に入っているかを確認
    if(v < min || v > max) return 0;
    *out = v;
    return 1;
}