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
    case 0: //�\���L�[����
        
        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode);
            state++;
        }

        //�`���[�g���A�����e
        
        if (STATE(0) & PAD_LEFT | STATE(0) & PAD_RIGHT | STATE(0) & PAD_UP | STATE(0) & PAD_DOWN) { success = true; }

        if (success)//������B�������㐁���o���������Ă��玟�Ɉڍs���Ăق����̂ň�xsuccess�t���O���I���ɂ��Ă����ŗ��������Ƃ��m�F���Ă���nextFlag���I���ɂ���
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

    case 1: //�E���`���[�g���A��

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

        //�`���[�g���A�����e
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

    case 2://���Ă�ʊm�F�B

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

        //�`���[�g���A�����e(�����`���[�g���A���̓��e��B�����Ă��Ȃ���fukidasi.cpp�̕��ł܂������o���Ƃ��݂����������B)
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

    case 3://������`���[�g���A��

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

        //�`���[�g���A�����e(�����`���[�g���A���̓��e��B�����Ă��Ȃ���fukidasi.cpp�̕��ł܂������o���Ƃ��݂����������B)
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

    case 4://�A�C�e���摜�\��
     
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

    case 5://�|�[�Y��ʃ`���[�g���A��
        
        if (state == 0)
        {
            FukidasiManager_.add(&fukidasi, VECTOR2(400, 84), mode - 1);
            data = nullptr;
            state++;
        }

        //�`���[�g���A�����e(�����`���[�g���A���̓��e��B�����Ă��Ȃ���fukidasi.cpp�̕��ł܂������o���Ƃ��݂����������B)
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