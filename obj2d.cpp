//******************************************************************************
//
//
//      obj2d
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <string>
#include <iostream>

#include "all.h"

//------< 変数 >----------------------------------------------------------------

float OBJ2D::no = 0;

//------< 構造体 >---------------------------------------------------------------

//------< プロトタイプ宣言 >-----------------------------------------------------

//--------------------------------
// 空きを探してOBJ2Dを生成する（Version2）
//--------------------------------
OBJ2D* searchSet(OBJ2D arr[], int arrayNum, int type, VECTOR2 pos)
{
    int i;
    for (i = 0; i < arrayNum; i++)
    {
        if (arr[i].exist == TRUE) continue;
        ZeroMemory(&arr[i], sizeof(OBJ2D));
        arr[i].type = type;
        arr[i].position = pos;
        arr[i].scale = VECTOR2(1, 1);
        arr[i].color = VECTOR4(1, 1, 1, 1);
        arr[i].exist = TRUE;
        return &arr[i]; // 生成したarr[i]のアドレスを返す
    }
    return NULL;        // 生成できなかったのでNULLを返す
}

//--------------------------------
// OBJ2Dのエリア外チェック
//--------------------------------
BOOL areaCheck(OBJ2D* obj, float limit)
{
    if (obj->position.x < -limit ||
        obj->position.x > system::SCREEN_WIDTH + limit ||
        obj->position.y < -limit ||
        obj->position.y > system::SCREEN_HEIGHT + limit)
    {
        obj->exist = FALSE;
    }

    return obj->exist;
}

//--------------------------------------------------------------
//  アニメーション更新
//--------------------------------------------------------------
//  戻り値：true  アニメが先頭に戻る瞬間
//        :false それ以外
//--------------------------------------------------------------
//bool OBJ2DC::animeUpdate()
//{
//    if (animeData == nullptr)
//    {
//        //assert(!"animeUpdate関数でAnimeDataがnullptr");
//        return false;
//    }
//
//    if (anime.pPrev != animeData)           // アニメデータが切り替わったとき
//    {
//        anime.pPrev = animeData;
//        anime.patNum = 0;	                // 先頭から再生
//        anime.frame = 0;
//    }
//
//    animeData += anime.patNum;
//    data = animeData->data;                 // 現在のパターン番号に該当する画像を設定
//
//    anime.frame++;
//    if (anime.frame >= animeData->frame)    // 設定フレーム数表示したら
//    {
//        anime.frame = 0;
//        anime.patNum++;                     // 次のパターンへ
//        if ((animeData + 1)->frame < 0)     // 終了コードのとき
//        {
//            anime.patNum = 0;               // 先頭へ戻る
//            return true;
//        }
//    }
//
//    return false;
//}


bool OBJ2D::animeUpdate(AnimeData* animeData)
{
    if (animeData == nullptr) assert(!"animeUpdate関数でAnimeDataがnullptr");
    if (anime.pPrev != animeData)           // アニメデータが切り替わったとき
    {
        anime.pPrev = animeData;
        anime.patNum = 0;	                // 先頭から再生
        anime.frame = 0;
    }

    animeData += anime.patNum;
    data = animeData->data;                 // 現在のパターン番号に該当する画像を設定

    anime.frame++;
    if (anime.frame >= animeData->frame)    // 設定フレーム数表示したら
    {
        anime.frame = 0;
        anime.patNum++;                     // 次のパターンへ
        if ((animeData + 1)->frame < 0)     // 終了コードのとき
        {
            anime.patNum = 0;               // 先頭へ戻る
            return true;
        }
    }
    return false;
}



//--------------------------------------------------------------
//  あたり判定の可視化
//--------------------------------------------------------------
void OBJ2D::drawHitRect(const VECTOR4& col)
{
    primitive::rect(
        VECTOR2(hitRect.left, hitRect.top),
        VECTOR2(hitRect.right - hitRect.left, hitRect.bottom - hitRect.top),
        VECTOR2(0, 0), 0,
        col);
}


void readData(std::string fileName, float& data)
{
    //getData data;

    std::ifstream ifs(fileName);

    assert(ifs);

    ifs >> data;
}




