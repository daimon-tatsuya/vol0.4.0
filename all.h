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
#include "dustbox.h"
#include "ui.h"
#include "timer.h"
#include "comb.h"
#include "randomMark.h"
#include "item.h"
#include "ranking.h"
#include "title.h"
#include "plate.h"
#include "effect.h"
#include "gameMode.h"
#include "scne_over.h"
#include "fukidasi.h"
#include "tutorial.h"
#include "pause.h"
#include "pressShutter.h"
#include "playerUI.h"
#include "pushBotton_B.h"
<<<<<<< HEAD

#include "kage.h"

=======
#include "kage.h"
>>>>>>> 53df2037096848fddef3a20852c25506411158da
#endif // !INCLUDED_ALL
