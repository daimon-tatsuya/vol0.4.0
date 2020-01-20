#include "all.h"

extern int nextScene;

void Tutorial::init()
{
    mode = 0;
    state = 0;
    timer = 0;
    nextFlag = false;
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
        if (STATE(0) & PAD_LEFT | STATE(0) & PAD_RIGHT | STATE(0) & PAD_UP | STATE(0) & PAD_DOWN) { nextFlag = true; }

        if (nextFlag)
        {
            timer++;
            if (timer > 300)
            {
                state = 0;
                timer = 0;
                nextFlag = false;
                mode++;

            }
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
            if (it.caughtFlg) { nextFlag = true; }
        }
        if (nextFlag)
        {
            timer++;
            if (timer > 300)
            {
                state = 0;
                timer = 0;
                nextFlag = false;
                mode++;
            }
        }
        break;

    case 2://投げるチュートリアル

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

        //チュートリアル内容
        for (auto& it : *GarbageManager_.getList())
        {
            if (it.throwFlg) { nextFlag = true; }
        }

        if (nextFlag)
        {
            timer++;
            if (timer > 150)
            {
                state = 0;
                timer = 0;
                nextFlag = false;
                mode++;
            }
        }
        break;

    case 3://アイテム画像表示
        
        for (auto& it : *FukidasiManager_.getList())
        {
            if (it.type == mode - 1) { it.eraseAlg = &fukidasiErase; }
        }

        data = &sprItiran;
        if (TRG(0) & PAD_TRG1)
        {
            nextScene = SCENE_TITLE;
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