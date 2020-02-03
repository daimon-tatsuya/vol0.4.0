//******************************************************************************
//
//
//      audio
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< namespace >-----------------------------------------------------------
using namespace GameLib;

//--------------------------------
//  �����ݒ�
//--------------------------------
void audio_init()
{ //SE
    music::load(0, L"./Data/Musics/decision.wav", 0.4f);//����
    music::load(1, L"./Data/Musics/cancel.wav",   0.4f);//�L�����Z��
    music::load(2, L"./Data/Musics/press.wav",    1.0f);//�v���X
    music::load(3, L"./Data/Musics/shutter.wav",  1.0f);//�V���b�^�[
    music::load(4, L"./Data/Musics/item.wav",     0.5f);//�A�C�e������
  //BGM
    music::load(5, L"./Data/Musics/tittle.wav",   1.0f);//�^�C�g��
    music::load(6, L"./Data/Musics/battle.wav",   1.0f);//�o�g��
}

//--------------------------------B
//  �I������
//--------------------------------
void audio_uninit()
{
    // ���y�̉������
    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
        music::unload(i);
}
