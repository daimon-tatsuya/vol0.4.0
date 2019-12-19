#ifndef INCLUDED_OBJ2D_DATA
#define INCLUDED_OBJ2D_DATA

//******************************************************************************
//
//
//      OBJ2D_Data
//
//
//******************************************************************************

//------< �C���N���[�h >--------------------------------------------------------
#include "sprite.h"

namespace GameLib
{
    
    //==========================================================================
    //
    //      SpriteData
    //
    //==========================================================================
    struct SpriteData
    {
        int     texNo;              // �e�N�X�`���̃C���f�b�N�X
        float   left, top;          // �摜�؂�o���ʒu�i���A��j
        float   width, height;      // �摜�T�C�Y
        float   centerX, centerY;   // �摜�̒��S

        void draw(
            const VECTOR2&, 
            const VECTOR2& scale = ( VECTOR2(1, 1) ), 
            float angle = ( 0.0f ), 
            const VECTOR4& color = ( VECTOR4(1, 1, 1, 1) ));

        void draw(
            float x, float y,
            float scaleX = ( 1.0f ), float scaleY = ( 1.0f ),
            float angle = ( 0.0f ),
            float r = ( 1.0f ), float g = ( 1.0f ), float b = ( 1.0f ), float a = ( 1.0f )
            );
    };

    //==========================================================================
    //
    //      AnimeData
    //
    //==========================================================================
    struct AnimeData
    {
        SpriteData* data;   // �X�v���C�g�f�[�^
        int         frame;  // �\�����ԁi�t���[�����j
    };

    // �A�j���[�V�����p���[�N
    struct Anime
    {
        int        frame;    // �\�����ԁi�t���[�����j
        int        patNum;   // �p�^�[���ԍ�
        AnimeData* pPrev;    // �O��̃A�j���[�V�����f�[�^
    };

    //==========================================================================
    //
    //      fRECT
    //
    //==========================================================================
    struct fRECT
    {
        float left;
        float top;
        float right;
        float bottom;

        fRECT() : left(0), top(0), right(0), bottom(0) {}
        fRECT(float l, float t, float r, float b) : left(l), top(t), right(r), bottom(b) {}
    };
    
}

#endif// ! INCLUDED_OBJ2D_DATA
