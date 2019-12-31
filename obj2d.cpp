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

//--------------------------------------------------------------
//  �ړ�
//--------------------------------------------------------------
void OBJ2D::move()
{
    if (mvAlg) mvAlg->move(this);                   // �ړ��A���S���Y�������݂���΁Amove���\�b�h���Ă�
    if (eraseAlg) eraseAlg->erase(this);            // �����A���S���Y�������݂���΁Aerase���\�b�h���Ă�
}

//--------------------------------------------------------------
//  �`��
//--------------------------------------------------------------
void OBJ2D::draw()
{
    if (isDrawHitRect)
    {
        // �����蔻��̗̈���w�肵���F�œh��Ԃ�
        drawHitRect(VECTOR4(1.0f, 0.0f, 0.0f, 0.4f));
    }
    if (data)
    {
        data->draw(position, scale, angle, color);  // data��draw���\�b�h�ŃX�v���C�g��`�悷��
    }
}


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

void OBJ2DManager::init()
{
    //���X�g��OBJ2D��S�ăN���A����
    objList.clear();
}

//--------------------------------------------------------------
//  ���X�g�֒ǉ�
//--------------------------------------------------------------
OBJ2D* OBJ2DManager::add(MoveAlg* mvAlg, const VECTOR2& pos)
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}

//--------------------------------------------------------------
//  �X�V
//--------------------------------------------------------------
void OBJ2DManager::update()
{
    // �ړ�
    for (auto& it : objList)            // objList�̑S�Ă̗v�f�����[�v���Ait�Ƃ������O�Ŋe�v�f�ɃA�N�Z�X
    {
        it.move();                      // it��move���\�b�h���Ă�
    }

    // ��m�[�h�̍폜�i���͋C�ɂ��Ȃ��ėǂ��j
    auto it = objList.begin();
    while (it != objList.end())
    {
        if (it->mvAlg)
        {
            it++;
        }
        else
        {
            it = objList.erase(it);
        }
    }
}

//--------------------------------------------------------------
//  �`��
//--------------------------------------------------------------
void OBJ2DManager::draw()
{
    for (auto& it : objList)            // objList�̑S�Ă̗v�f�����[�v���Ait�Ƃ������O�Ŋe�v�f�ɃA�N�Z�X 
    {
        if (it.mvAlg)
        {
            it.draw();                      // it��draw���\�b�h���Ă�
        }
    }
}

//--------------------------------------------------------------
//  �f�X�g���N�^
//--------------------------------------------------------------
OBJ2DManager::~OBJ2DManager()
{
    //���X�g��OBJ2D��S�ăN���A����
    objList.clear();
}


void readData(std::string fileName, float& data)
{
    //getData data;

    std::ifstream ifs(fileName);

    assert(ifs);

    ifs >> data;
}




