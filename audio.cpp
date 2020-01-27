//******************************************************************************
//
//
//      audio
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< namespace >-----------------------------------------------------------
using namespace GameLib;

//--------------------------------
//  初期設定
//--------------------------------
void audio_init()
{ //SE
    music::load(0, L"./Data/Musics/decision.wav", 1.0f);//決定
    music::load(1, L"./Data/Musics/cancel.wav",   1.0f);//キャンセル
    music::load(2, L"./Data/Musics/press.wav",    1.0f);//プレス
    music::load(3, L"./Data/Musics/shutter.wav",  1.0f);//シャッター
    music::load(4, L"./Data/Musics/item.wav",     1.0f);//アイテム入手
  //BGM
    music::load(5, L"./Data/Musics/tittle.wav",   1.0f);//タイトル
    music::load(6, L"./Data/Musics/battle.wav",   1.0f);//バトル
}

//--------------------------------B
//  終了処理
//--------------------------------
void audio_uninit()
{
    // 音楽の解放処理
    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
        music::unload(i);
}
