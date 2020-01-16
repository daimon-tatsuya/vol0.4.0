#include "all.h"

using namespace GameLib;
using namespace system;

float belt = 2.0f;//ベルトコンベアーの強制移動


void Player::init()
{
}

void Player::update()
{
    using namespace input;
   
    animeData = nullptr;

    switch (state)
    {
    case PLAYER_INIT://初期設定 1

        animeData = animePlayer_Down;

        // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
        size = VECTOR2(24 / 2, 32 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        GROUND_POS_Y = 570.0f;
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        iWork[PLAYER::LIFTED_MAX] = 3;

        if (animeData)
        {
            animeUpdate(animeData);
        }

        state++;
        break;

    case PLAYER_MOVE://動き

        //スピードアップアイテムをとった時一定時間コンベアーのスピードアップ。
        if (player[type].bWork[PLAYER_STATUS::SPEEDUP] && player[type].timer < 360) { player[type].timer++; }
        else if(player[type].bWork[PLAYER_STATUS::SPEEDUP])
        {
            player[type].bWork[PLAYER_STATUS::SPEEDUP] = false;
            player[type].timer = 0;
            belt = 2.0f;
        }

        //スピードダウンアイテムをとった時一定時間コンベアーのスピードダウン。
        if (player[type].bWork[PLAYER_STATUS::SPEEDDOWN] && player[type].timer < 360) {
            player[type].timer++; }
        else if (player[type].bWork[PLAYER_STATUS::SPEEDDOWN])
        {
            player[type].bWork[PLAYER_STATUS::SPEEDDOWN] = false;
            player[type].timer = 0;
            belt = 2.0f;
        }


        //ベルトコンベアーの強制移動
        speed = { 0,0 };
        speed.x = belt;
        
       

            if (STATE(type) & PAD_LEFT)//左移動
            {
                animeData = animePlayer_Left;
                speed.x += -4;
                xFlip = -1.0f;
            }
            if (STATE(type) & PAD_RIGHT)//右移動
            {
                animeData = animePlayer_Right;
                speed.x += 3;
                xFlip = 1.0f;
            }
            if (STATE(type) & PAD_UP) //上移動
            {
                animeData = animePlayer_Up;
                speed.y = -1;
            }
            if (STATE(type) & PAD_DOWN) //下移動
            {
                animeData = animePlayer_Down;
                speed.y = 1;
            }
       
            
       
        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //移動\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        position += speed;
       

        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        ////ジャンプ\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

        //if (onGround && TRG(0)&PAD_TRG3)
        //{
        //    jumpTimer = 10;
        //}
        //if (jumpTimer > 0)
        //{
        //    if (STATE(0) & PAD_TRG3)
        //    {
        //        speed.y += jump;
        //        jumpTimer -= 1;
        //    }
        //}
        //else
        //{
        //    jumpTimer = 0;
        //}

        //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
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