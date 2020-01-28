#include "all.h"

using namespace system;

extern float belt;//�x���g�R���x�A�[�̋����ړ�

//int groundPosYKeep_Item = 0;
void Item::move(OBJ2D* obj)
{
    if (obj->state == 0)
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
            obj->GROUND_POS_Y = 448.0f;//��
            obj->scale = VECTOR2(0.9f, 0.9f);
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y + 32));
            break;
        case 1:
            obj->GROUND_POS_Y = 546.0f;//��
            obj->scale = VECTOR2(0.95f, 0.95f);
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y));
            break;
        case 2:
            obj->GROUND_POS_Y = 610.0f;//��
            KageManager_.add(&kage, VECTOR2(obj->position.x, obj->GROUND_POS_Y));
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

void itemMove1(OBJ2D* obj) //�R���x�A�[�X�s�[�h�A�b�v
{
    switch (obj->state)
    {
    case ITEM_INIT://�����ݒ�

        obj->data = &sprItem0;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        // obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }
           
            //�A�j���A�b�v�f�[�g
            //if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    
                    //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
                    player[i].bWork[PLAYER_STATUS::CONVEYORUP] = true;
                    conveyor.animeData = animeConveyor[1];
                    belt = 3.5f;
                    obj->eraseAlg = &itemErase;
                }
               
            }
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//��1200�̓R���x�A�[�̉E�[
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove2(OBJ2D* obj)//���̑������オ��A�C�e�������B
{
    switch (obj->state)
    {
    case ITEM_INIT://�����ݒ�
        obj->data = &sprItem1;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {

            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //�A�j���A�b�v�f�[�g
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }
                          
            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
                if (player[i].exist)
                {
                    if (player[i].bWork[PLAYER_STATUS::SPEEDUP] == true) //�������ʂ̃G�t�F�N�g���o�Ă�ꍇ�͂�����������B
                    {
                        for (auto& efe : *EffectManager_.getList())
                        {
                            if (efe.exist && efe.type == 1)
                            {
                                efe.eraseAlg = &effectErase;
                                break;
                            }
                        }
                    }
                    player[i].bWork[PLAYER_STATUS::SPEEDUP] = true;
                    EffectManager_.add(&effect, player[i].position, 1, i);
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//��1200�̓R���x�A�[�̉E�[
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove3(OBJ2D* obj)//���Ă�ʑ�����A�C�e�������B
{
    switch (obj->state)
    {
    case ITEM_INIT://�����ݒ�
        obj->data = &sprItem2;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {
            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //�A�j���A�b�v�f�[�g
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
                    if (player[i].bWork[PLAYER_STATUS::POWERUP] == true) //�������ʂ̃G�t�F�N�g���o�Ă�ꍇ�͂�����������B
                    {
                        for (auto& efe : *EffectManager_.getList())
                        {
                            if (efe.exist && efe.type == 0)
                            {
                                efe.eraseAlg = &effectErase;
                                break;
                            }
                        }
                    }
                    player[i].bWork[PLAYER_STATUS::POWERUP] = true;
                    player[i].iWork[PLAYER::LIFTED_MAX] = 4;
                    EffectManager_.add(&effect, player[i].position, 0, i);
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//��1200�̓R���x�A�[�̉E�[
        {
            obj->state++;
        }

        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
        break;
    }
}

void itemMove4(OBJ2D* obj)//�A�C�e���o�����ԒZ�k
{
    switch (obj->state)
    {
    case ITEM_INIT://�����ݒ�
        obj->data = &sprItem3;
        obj->size = VECTOR2(27, 32 - 2); //�X�P�[���͓����蔻��̒l�Ȃ̂Ŏ��ۂ̑傫���̔���������
        obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
        //obj->position = { SCREEN_WIDTH / 2,GROUND_POS_Y };
        obj->speed = VECTOR2(0, 4);

        obj->state++;
        break;

    case ITEM_DROP:

        obj->position.y += obj->speed.y;

        if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            obj->position.y = obj->GROUND_POS_Y;
            obj->state++;
        }
        break;

    case ITEM_MOVE:
        for (int i = 0; i < 2; i++)
        {

            if (rectHitCheck(obj->position - VECTOR2(32, 64), 64, 64, VECTOR2(0, obj->GROUND_POS_Y), SCREEN_WIDTH, SCREEN_HEIGHT))
            {
                obj->position.y = obj->GROUND_POS_Y;
            }

            //�A�j���A�b�v�f�[�g
            if (obj->animeData) { obj->animeUpdate(obj->animeData); }

            if (obj->position.y > SCREEN_HEIGHT || obj->position.x > SCREEN_WIDTH) { obj->eraseAlg = &garbageErase; }

            if (rectHitCheck(VECTOR2(obj->position.x - obj->size.x, obj->position.y - obj->size.y), obj->size.x, obj->size.y, VECTOR2(player[i].position.x - player[i].size.x, player[i].position.y - player[i].size.y), player[i].size.x, player[i].size.y))
            {
                music::play(4);
                if (player[i].exist)
                {
                    //�����ɃA�C�e�����ʂ̏����̃t���O�𗧂Ă�B
                    for (auto& it : *RandoManager_.getList())
                    {
                        it.iWork[RandoManager::RandoMark::TIMER_MAX1] = 120;
                        it.iWork[RandoManager::RandoMark::TIMER_MAX2] = 240;
                    }
                    player[i].bWork[PLAYER_STATUS::ITEMADD] = true;
                    obj->eraseAlg = &itemErase;
                }
            }
        }

        //�x���g�R���x�A�[�̋����ړ�
        obj->speed.x = belt;

        obj->position += obj->speed;

        if (obj->position.x > 1092.0f)//��1200�̓R���x�A�[�̉E�[
        {
            obj->state++;
        }
        break;
    case ITEM_DELETE:
        obj->speed.y = 3;
        obj->speed.x = 1;
        if (obj->position.y < (-obj->size.y*2.0f))
        {
            obj->eraseAlg = &itemErase;
        }
        obj->position += obj->speed;
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