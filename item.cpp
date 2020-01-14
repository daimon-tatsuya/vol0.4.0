#include "all.h"

using namespace system;

extern float belt;//�x���g�R���x�A�[�̋����ړ�

//int groundPosYKeep_Item = 0;
void Item::move(OBJ2D* obj)
{
    if(obj->state == 0)
    {
        int groundPosY = rand() % 3;//�����p

        while (1)
        {
            if (groundPosYKeep_Item != groundPosY) { break; }
            groundPosY = rand() % 3;
        }


        switch (groundPosY)
        {
        case 0:
            obj->GROUND_POS_Y = 482.0f;//��
            break;
        case 1:
            obj->GROUND_POS_Y = 546.0f;//��
            break;
        case 2:
            obj->GROUND_POS_Y = 610.0f;//��
            break;
        }
        groundPosYKeep_Item = groundPosY;
    }
    switch (obj->type)
    {
    case 1:

        itemMove1(obj);
        break;

    case 2:

        itemMove2(obj);
        break;

    case 3:

        itemMove3(obj);
        break;

    case 4:

        itemMove4(obj);
        break;
    }
}

void itemMove1(OBJ2D* obj) //�X�s�[�h�A�b�v
{
    switch (obj->state)
    {
    case 0://�����ݒ�


        obj->data = &sprItem0;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        // obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;


        //�A�j���A�b�v�f�[�g
        //if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
            player.bWork[PLAYER_STATUS::SPEEDUP] = true;
            belt = 3.5f;
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove2(OBJ2D* obj)//�X�s�[�h�_�E��
{
    switch (obj->state)
    {
    case 0://�����ݒ�
        obj->data = &sprItem1;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        //�A�j���A�b�v�f�[�g
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
            player.bWork[PLAYER_STATUS::SPEEDDOWN] = true;
            belt = 0.5f;
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove3(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://�����ݒ�
        obj->data = &sprItem2;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        //�A�j���A�b�v�f�[�g
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B

            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void itemMove4(OBJ2D* obj)
{
    switch (obj->state)
    {
    case 0://�����ݒ�
        obj->data = &sprItem3;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed.y = 4;

        obj->state++;
        break;

    case 1:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case 2:

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        //�A�j���A�b�v�f�[�g
        if (obj->animeData) { obj->animeUpdate(obj->animeData); }

        if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

        if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player.position.x - player.size.x, player.position.y - player.size.y), player.size.x, player.size.y))
        {
            //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
            obj->eraseAlg = &itemErase;
        }

        break;
    }
}

void ItemErase::erase(OBJ2D* obj)
{
    obj->mvAlg = nullptr;
}

OBJ2D* ItemManager::add(MoveAlg* mvAlg, const VECTOR2& pos, int type) // objList�ɐV����OBJ2D��ǉ�����
{
    OBJ2D obj;                          // OBJ2D��錾����
    obj.mvAlg = mvAlg;                  // mvAlg�Ɉ�����mvalg����
    obj.position = pos;                 // position�Ɉ�����pos����
    obj.type = type;                    //type�ݒ�

    objList.push_back(obj);             // ���X�g��obj��ǉ�����
    return &(*objList.rbegin());        // ���ǉ�����obj�̃A�h���X��Ԃ��i�����Ŏg����悤�Ɂj
}