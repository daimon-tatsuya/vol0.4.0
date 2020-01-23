#pragma once
//#include "./GameLib/game_lib.h"
//#include "./GameLib/obj2d_data.h"
//#include "work.h"

class Shutter
{
public:
    GameLib::SpriteData* data = nullptr;// �X�v���C�g�f�[�^

    VECTOR2 position = VECTOR2(0, 0);
    VECTOR2 scale = { 1, 1 };           // �X�P�[��
    float   angle = 0;                  // �p�x
    VECTOR4 color = VECTOR4(0, 0, 0, 0);//�F
    int     type = 0;                  //�X�N���[���A�b�v���_�E���������ʂ��邽�߂̕ϐ��B

    void init();
    // void update();
    bool scrollUp();
    bool scrollDown();
    void draw();
};

EXTERN Shutter shutter;