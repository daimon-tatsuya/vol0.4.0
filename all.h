#ifndef INCLUDED_ALL
#define INCLUDED_ALL

//******************************************************************************
//
//
//      all.h
//
//
//******************************************************************************

//------< ゲームライブラリ >-----------------------------------------------------
#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"

//------< namespace >-----------------------------------------------------------
using namespace GameLib;    // 本来ヘッダに書くべきではない（学習しやすさを優先）
using namespace input;      // 本来ヘッダに書くべきではない（学習しやすさを優先）

//------< インクルード >---------------------------------------------------------
#include "common.h"
#include "audio.h"
#include "scene_title.h"
#include "obj2d.h"
#include "scene_game.h"
#include "sprite_data.h"
#include "work.h"
#include "player.h"
#include "garbage.h"
#include "judge.h"
#include "pressMachine.h"
#include "BG.h"
#include "conveyor.h"
#include "ber.h"
#include "dustbox.h"
//******************************************************************************
#endif // !INCLUDED_ALL
