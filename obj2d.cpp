//******************************************************************************
//
//
//      obj2d
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <string>
#include <iostream>

#include "all.h"

//------< �ϐ� >----------------------------------------------------------------

float OBJ2D::no = 0;

//------< �\���� >---------------------------------------------------------------

//------< �v���g�^�C�v�錾 >-----------------------------------------------------

//--------------------------------
// �󂫂�T����OBJ2D�𐶐�����iVersion2�j
//--------------------------------
OBJ2D* searchSet(OBJ2D arr[], int arrayNum, int type, VECTOR2 pos)
{
    int i;
    for (i = 0; i < arrayNum; i++)
    {
        if (arr[i].exist == TRUE) continue;
        ZeroMemory(&arr[i], sizeof(OBJ2D));
        arr[i].type = type;
        arr[i].position = pos;
        arr[i].scale = VECTOR2(1, 1);
        arr[i].color = VECTOR4(1, 1, 1, 1);
        arr[i].exist = TRUE;
        return &arr[i]; // ��������arr[i]�̃A�h���X��Ԃ�
    }
    return NULL;        // �����ł��Ȃ������̂�NULL��Ԃ�
}

//--------------------------------
// OBJ2D�̃G���A�O�`�F�b�N
//--------------------------------
BOOL areaCheck(OBJ2D* obj, float limit)
{
    if (obj->position.x < -limit ||
        obj->position.x > system::SCREEN_WIDTH + limit ||
        obj->position.y < -limit ||
        obj->position.y > system::SCREEN_HEIGHT + limit)
    {
        obj->exist = FALSE;
    }

    return obj->exist;
}

//--------------------------------------------------------------
//  �A�j���[�V�����X�V
//--------------------------------------------------------------
//  �߂�l�Ftrue  �A�j�����擪�ɖ߂�u��
//        :false ����ȊO
//--------------------------------------------------------------
//bool OBJ2DC::animeUpdate()
//{
//    if (animeData == nullptr)
//    {
//        //assert(!"animeUpdate�֐���AnimeData��nullptr");
//        return false;
//    }
//
//    if (anime.pPrev != animeData)           // �A�j���f�[�^���؂�ւ�����Ƃ�
//    {
//        anime.pPrev = animeData;
//        anime.patNum = 0;	                // �擪����Đ�
//        anime.frame = 0;
//    }
//
//    animeData += anime.patNum;
//    data = animeData->data;                 // ���݂̃p�^�[���ԍ��ɊY������摜��ݒ�
//
//    anime.frame++;
//    if (anime.frame >= animeData->frame)    // �ݒ�t���[�����\��������
//    {
//        anime.frame = 0;
//        anime.patNum++;                     // ���̃p�^�[����
//        if ((animeData + 1)->frame < 0)     // �I���R�[�h�̂Ƃ�
//        {
//            anime.patNum = 0;               // �擪�֖߂�
//            return true;
//        }
//    }
//
//    return false;
//}


bool OBJ2D::animeUpdate(AnimeData* animeData)
{
    if (animeData == nullptr) assert(!"animeUpdate�֐���AnimeData��nullptr");
    if (anime.pPrev != animeData)           // �A�j���f�[�^���؂�ւ�����Ƃ�
    {
        anime.pPrev = animeData;
        anime.patNum = 0;	                // �擪����Đ�
        anime.frame = 0;
    }

    animeData += anime.patNum;
    data = animeData->data;                 // ���݂̃p�^�[���ԍ��ɊY������摜��ݒ�

    anime.frame++;
    if (anime.frame >= animeData->frame)    // �ݒ�t���[�����\��������
    {
        anime.frame = 0;
        anime.patNum++;                     // ���̃p�^�[����
        if ((animeData + 1)->frame < 0)     // �I���R�[�h�̂Ƃ�
        {
            anime.patNum = 0;               // �擪�֖߂�
            return true;
        }
    }
    return false;
}



//--------------------------------------------------------------
//  �����蔻��̉���
//--------------------------------------------------------------
void OBJ2D::drawHitRect(const VECTOR4& col)
{
    primitive::rect(
        VECTOR2(hitRect.left, hitRect.top),
        VECTOR2(hitRect.right - hitRect.left, hitRect.bottom - hitRect.top),
        VECTOR2(0, 0), 0,
        col);
}


void readData(std::string fileName, float& data)
{
    //getData data;

    std::ifstream ifs(fileName);

    assert(ifs);

    ifs >> data;
}




