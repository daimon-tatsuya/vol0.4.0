#include "all.h"

using namespace GameLib;
using namespace system;

float belt = 2.0f;//ベルトコンベアーの強制移動


void Player::init()
{
    //position = {SCREEN_WIDTH / 2,GROUND_POS_Y};
    //scale = VECTOR2(1.0f, 1.0f);//1.0f,1.0f
    //color = VECTOR4(1, 1, 1, 1);
    //
    //state = 0;
    //inversion = 1;
    //angle =1;
    //
    //exist = TRUE; // プレイヤーが存在している
    //
    //onGround = true;
}

void Player::update()
{
    using namespace input;
    constexpr float SpeedMax = 8.0f;
    constexpr float jump = -10.f;
    constexpr float GROUND_POS_Y = 570.0f;
    animeData = nullptr;

    switch (state)
    {
    case PLAYER_INIT://初期設定 1

        animeData = animePlayer_Down;

        // サイズ設定（足元が中心であるため、幅はあたりとして使用する半分・縦はそのままが扱いやすい）
        size = VECTOR2(24 / 2, 64 - 2);
        color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        position = { SCREEN_WIDTH / 2,GROUND_POS_Y };

        if (animeData)
        {
            animeUpdate(animeData);
        }

        state++;
        break;

    case PLAYER_MOVE://動き
        //onGround = false;
        //speed.y += 0.5f;
        //position.y += speed.y;
        //if (speed.y < -SpeedMax)
        //{
        //    speed.y = -SpeedMax;
        //}
        //if (position.y > GROUND_POS_Y)
        //{
        //    position.y = GROUND_POS_Y;
        //    onGround = true;
        //    //Player.attackFlg = true;
        //}

        //左右操作\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
        //何も押してないとき
        //ベルトコンベアーの強制移動
        speed = { 0,0 };
        speed.x = belt;
        
       

            if (STATE(0) & PAD_LEFT)//左移動
            {
                animeData = animePlayer_Left;
                speed.x = -3;
            }
            if (STATE(0) & PAD_RIGHT)//右移動
            {
                animeData = animePlayer_Right;
                speed.x = 3;
            }
            if (STATE(0) & PAD_UP) //上移動
            {
                animeData = animePlayer_Up;
                speed.y = -1;
            }
            if (STATE(0) & PAD_DOWN) //下移動
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
        
        if (position.x < size.x/* / 2 */)
        {
            position.x = size.x /*/ 2*/;
            speed.x = 0;
        }

        if (position.x > system::SCREEN_WIDTH - (size.x*8.0f)/* / 2*/)
        {
            position.x = system::SCREEN_WIDTH - (size.x*8.0f) /*/ 2*/;
            speed.x = 0;
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