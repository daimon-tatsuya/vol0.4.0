#include "all.h"

extern int game_state;
extern int nextScene;

void Tutorial::init()
{
    mode = 0;
    tutoriaFlag = false;
    state = 0;
    timer = 0;
    nextFlag = false;
    success = false;
    data = nullptr;
}


void Tutorial::update()
{
    switch (mode)
    {
    case 0: //十字キー操作
        
        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode);
            state++;
        }

        //チュートリアル内容
        
        if (STATE(0) & PAD_LEFT | STATE(0) & PAD_RIGHT | STATE(0) & PAD_UP | STATE(0) & PAD_DOWN) { success = true; }

        if (success)//条件を達成した後吹き出しが落ちてから次に移行してほしいので一度successフラグをオンにしてそこで落ちたことを確認してからnextFlagをオンにする
        {
            for (auto& it : *FukidasiManager_.getList())
            {
                if (it.state == GARBAGE_DELETE) { nextFlag = true; }
            }
        }

        if (nextFlag)
        {            
            state = 0;
            timer = 0;
            nextFlag = false;
            success = false;
            mode++;
        }
        break;

    case 1: //拾うチュートリアル

        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode);
            GarbageManager_.add(&garbage, VECTOR2(653, 105), 0);
            for ( auto& it : *FukidasiManager_.getList())
            {
                if (it.type == mode - 1) { it.eraseAlg = &fukidasiErase; }
            }
            state++;
        }

        //チュートリアル内容
        for ( auto& it : *GarbageManager_.getList() )
        {
            if (it.caughtFlg) { success = true; }
        }

        if (success)
        {
            for (auto& it : *FukidasiManager_.getList())
            {
                if (it.state == GARBAGE_DELETE) { nextFlag = true; }
            }
        }

        if (nextFlag)
        {            
            state = 0;
            timer = 0;
            nextFlag = false;
            success = false;
            mode++;            
        }
        break;

    case 2://持てる量確認。

        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode);
            GarbageManager_.add(&garbage, VECTOR2(653, 105), 0);
            for (auto& it : *FukidasiManager_.getList())
            {
                if (it.type == mode - 1) { it.eraseAlg = &fukidasiErase; }
            }
            state++;
        }

        //チュートリアル内容(もしチュートリアルの内容を達成していないとfukidasi.cppの方でまた吹き出しとごみが生成される。)
        for (auto& it : *FukidasiManager_.getList())
        {
            if (player[0].liftedCount > 1 && it.state == GARBAGE_DELETE) { nextFlag = true; }
        }

        if (nextFlag)
        {            
            state = 0;
            timer = 0;
            nextFlag = false;
            success = false;
            mode++;
        }

        break;

    case 3://投げるチュートリアル

        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode);
            GarbageManager_.add(&garbage, VECTOR2(653, 105), 0);
            for (auto& it : *FukidasiManager_.getList())
            {
                if (it.type == mode - 1) { it.eraseAlg = &fukidasiErase; }
            }
            state++;
        }

        //チュートリアル内容(もしチュートリアルの内容を達成していないとfukidasi.cppの方でまた吹き出しとごみが生成される。)
        for (auto& it : *GarbageManager_.getList())
        {
            if (it.throwFlg && tutoriaFlag) { success = true; }
        }

        if (success)
        {
            for (auto& it : *FukidasiManager_.getList())
            {
                if (it.state == GARBAGE_DELETE) { nextFlag = true; }
            }
        }

        if (nextFlag)
        {                        
            state = 0;
            timer = 0;
            nextFlag = false;
            success = false;
            mode++;
        }
        break;

    case 4://アイテム画像表示
     
        for (auto& it : *FukidasiManager_.getList())
        {
            if (it.type == mode - 1) { it.eraseAlg = &fukidasiErase; }
        }

        data = &sprItiran;
        if (TRG(0) & PAD_TRG2)
        {
            state = 0;
            timer = 0;
            nextFlag = false;            
            mode++;
        }
        break;

    case 5://ポーズ画面チュートリアル
        
        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode - 1);
            data = nullptr;
            state++;
        }

        //チュートリアル内容(もしチュートリアルの内容を達成していないとfukidasi.cppの方でまた吹き出しとごみが生成される。)
        for (auto& it : *FukidasiManager_.getList())
        {
            if (it.state == GARBAGE_DELETE && tutoriaFlag) { success = true; }
        }

        if (success)
        {
            if (shutter.scrollDown()) { nextFlag = true; }
        }

        if (nextFlag)
        {            
            nextScene = SCENE_TITLE;

            state = 0;
            timer = 0;
            nextFlag = false;
            success = false;
        }
        break;
    }
}

void Tutorial::draw()
{
    if (data)
    {
        data->draw(position);
    }
}