#include "all.h"

using namespace GameLib;
using namespace system;

float belt = 2.0f;//ベルトコンベアーの強制移動


void Player::init()
{
    if (type == 0)
    {
        animeData = animePlayer_Down;
    }
   

    // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
    size = VECTOR2(24 / 2, 32 - 2);
    color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
    GROUND_POS_Y = 570.0f;
    speed = VECTOR2(0, 0);
    position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
    iWork[PLAYER::CONVETIMER] = 0;
    iWork[PLAYER::ITEMADDTIMER] = 0;
    iWork[PLAYER::POWERTIMER] = 0;
    iWork[PLAYER::SPEEDTIMER] = 0;
    iWork[PLAYER::LIFTED_MAX] = 3;
    bWork[PLAYER_STATUS::CONVEYORUP] = false;
    bWork[PLAYER_STATUS::ITEMADD] = false;
    bWork[PLAYER_STATUS::POWERUP] = false;
    bWork[PLAYER_STATUS::SPEEDUP] = false;
    itemSpeed = 0;
    belt = 2.0f;

    if (animeData)
    {
        animeUpdate(animeData);
    }
}

void Player::update()
{
    using namespace input;
   
    animeData = nullptr;

    switch (state)
    {
    case PLAYER_INIT://初期設定 1

        if (type == 0)
        {
            animeData = animePlayer_Down;
        }

        // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
        size = VECTOR2(24 / 2, 32 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        GROUND_POS_Y = 570.0f;
        speed = VECTOR2(0, 0);
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        iWork[PLAYER::CONVETIMER]   = 0;
        iWork[PLAYER::ITEMADDTIMER] = 0;
        iWork[PLAYER::POWERTIMER]   = 0;
        iWork[PLAYER::SPEEDTIMER]   = 0;
        iWork[PLAYER::LIFTED_MAX]   = 3;
        bWork[PLAYER_STATUS::CONVEYORUP] = false;
        bWork[PLAYER_STATUS::ITEMADD]    = false;
        bWork[PLAYER_STATUS::POWERUP]    = false;
        bWork[PLAYER_STATUS::SPEEDUP]    = false;
        itemSpeed = 0;
        belt = 2.0f;

        if (animeData)
        {
            animeUpdate(animeData);
        }

        state++;
        break;

    case PLAYER_MOVE://動き

        //スピードアップアイテムをとった時一定時間コンベアーのスピードアップ。
        if (player[type].bWork[PLAYER_STATUS::CONVEYORUP] && player[type].iWork[PLAYER::CONVETIMER] < 360) { player[type].iWork[PLAYER::CONVETIMER]++; }
        else if(player[type].bWork[PLAYER_STATUS::CONVEYORUP])
        {
            player[type].bWork[PLAYER_STATUS::CONVEYORUP] = false;
            player[type].iWork[PLAYER::CONVETIMER] = 0;
            belt = 2.0f;
        }

        //足のスピードアップアイテムをとった時一定時間プレイヤーのスピードアップ。
        if (player[type].bWork[PLAYER_STATUS::SPEEDUP] && player[type].iWork[PLAYER::SPEEDTIMER] < 360)
        {
            player[type].iWork[PLAYER::SPEEDTIMER]++;
            player[type].itemSpeed = 2;
        }
        else if (player[type].bWork[PLAYER_STATUS::SPEEDUP])
        {
            player[type].bWork[PLAYER_STATUS::SPEEDUP] = false;
            player[type].itemSpeed = 0;
            player[type].iWork[PLAYER::SPEEDTIMER] = 0;
            for ( auto& efe : *EffectManager_.getList() )
            {
                if (efe.position == position)
                {
                    efe.eraseAlg = &effectErase;
                    break;
                }
            }
        }

        //一定時間持てる量増やす
        if (player[type].bWork[PLAYER_STATUS::POWERUP] && player[type].iWork[PLAYER::POWERTIMER] < 720)
        {
            player[type].iWork[PLAYER::POWERTIMER]++;
        }
        else if (player[type].bWork[PLAYER_STATUS::POWERUP])
        {
            player[type].bWork[PLAYER_STATUS::POWERUP] = false;
            player[type].iWork[PLAYER::LIFTED_MAX] = 3;
            player[type].iWork[PLAYER::POWERTIMER] = 0;
            for (auto& efe : *EffectManager_.getList())
            {
                if (efe.position == position)
                {
                    efe.eraseAlg = &effectErase;
                    break;
                }
            }
        }

        //一定時間アイテム出現量アップ
        if (player[type].bWork[PLAYER_STATUS::ITEMADD] && player[type].iWork[PLAYER::ITEMADDTIMER] < 600)
        {
            player[type].iWork[PLAYER::ITEMADDTIMER]++;
        }
        else if (player[type].bWork[PLAYER_STATUS::ITEMADD])
        {
            player[type].bWork[PLAYER_STATUS::ITEMADD] = false;            
            player[type].iWork[PLAYER::ITEMADDTIMER] = 0;

            for (auto& it : *RandoManager_.getList())
            {
                it.iWork[RandoManager::RandoMark::TIMER_MAX1] = 180;
                it.iWork[RandoManager::RandoMark::TIMER_MAX2] = 240;
            }
        }


        //ベルトコンベアーの強制移動
        speed.y = 0;
        speed.x = belt;
               

            if (STATE(type) & PAD_LEFT)//左移動
            {
                if (type == 0)
                {
                    animeData = animePlayer_Left;
                }
                speed.x += -4 - itemSpeed;
                xFlip = -1.0f;
            }
            if (STATE(type) & PAD_RIGHT)//右移動
            {
                if (type == 0)
                {
                    animeData = animePlayer_Right;
                }
                speed.x += 3 + itemSpeed;
                xFlip = 1.0f;
            }
            if (STATE(type) & PAD_UP) //上移動
            {
                if (type == 0)
                {
                    animeData = animePlayer_Up;
                }

                speed.y += -1 - itemSpeed;
            }
            if (STATE(type) & PAD_DOWN) //下移動
            {
                if (type == 0)
                {
                    animeData = animePlayer_Down;
                }
               
                speed.y = 1 + itemSpeed;
            }
       
            
       
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //移動\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        position += speed;
       

        //移動制限\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        if (position.x < 330)
        {
            position.x = 330;
            speed.x = 0;
        }

        if (position.x > system::SCREEN_WIDTH - (size.x*8.0f)/* / 2*/)
        {
            position.x = system::SCREEN_WIDTH - (size.x*8.0f) /*/ 2*/;
            speed.x = 0;
        }

        if (position.y < 432)
        {
            position.y = 432;
            speed.y = 0;
        }

        if (position.y > 610)
        {
            position.y = 610;
            speed.y = 0;
        }
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
      
        break;

    }
    //アニメアップデート
    if (animeData)
    { animeUpdate(animeData); }

}
     


void Player::draw()
{
    if (data)
    { data->draw(position, scale, angle, color); }

}