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
#include "work.h"
#include "common.h"
#include "audio.h"
#include "scene_title.h"
#include "obj2d.h"
#include "scene_game.h"
#include "sprite_data.h"
#include "player.h"
#include "garbage.h"
#include "judge.h"
#include "pressMachine.h"
#include "BG.h"
#include "conveyor.h"
#include "ber.h"
//<<<<<<< HEAD

//=======
#include "dustbox.h"
#include "ui.h"
#include "timer.h"
#include "comb.h"
//<<<<<<< HEAD
//>>>>>>> 0ecd60dfe11cdb69557f833ea8a896513ec56bde
//=======
#include "randomMark.h"
#include "item.h"
//<<<<<<< HEAD
//>>>>>>> 0109f21d0b202314af7c1d09622182140ff74ef5
//=======
#include "ranking.h"
//>>>>>>> a24f0345bfffecba1977123f24777fafc7059949
//******************************************************************************
#endif // !INCLUDED_ALL
