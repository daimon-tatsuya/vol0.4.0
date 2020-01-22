#pragma once
#include "all.h"

extern int combNum[2];
extern int combKeta[2];
extern int timerNum;
extern int timerKeta;

typedef struct
{
    char name[100];

    int score;
}RANK_UI;

class UI : public MoveAlg //move�֐���錾���Ă��Ȃ��̂Œ��ۃN���X
{
public:        

    static int resultKeta[];
    static int resultScore[];

    

    void timerMove(OBJ2D*);

    void combMove(OBJ2D*);

    void comb2Move(OBJ2D*);//�v���C���[2�p

    void randoMark(OBJ2D*);

    void rankingMove(OBJ2D*);
};
