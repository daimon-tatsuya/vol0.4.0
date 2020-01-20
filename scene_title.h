#ifndef INCLUDED_SCENE_TITLE
#define INCLUDED_SCENE_TITLE

//******************************************************************************
//
//
//      scene_title.h
//
//
//******************************************************************************

//------< プロトタイプ宣言 >-----------------------------------------------------
void title_init();
void title_update();
void title_draw();
void title_end();
extern bool twoPlayMode;
extern bool tutorialMode;//trueの時２人プレイ
#endif // !INCLUDED_SCENE_TITLE
