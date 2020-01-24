#pragma once
#define RESULT_MAX (6)


class Ranking
{

public:    
    GameLib::SpriteData*    data = nullptr;         // スプライトデータ

    int result[7] = { 1, 2, 4, 7, 2, 0, 0 };
    int copy = 0;

    int KetaCount[7];

    VECTOR2 pos;

    int state = 0;

    void readData();
    void writeData();
    void KetaCountMove();   
    void init();
    void update();
    void draw();
    void end();
};

EXTERN Ranking ranking;

class RankingNum : public UI
{
public:       
    void  move(OBJ2D*);
};

EXTERN RankingNum rankingNum;

class RankingNumErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

EXTERN RankingNumErase rankingNumErase;

class RankingNumManager : public OBJ2DManager
{    
public:
    enum RANKNUM
    {
        COPY,
        KETA,
    };
    OBJ2D* add(MoveAlg* mvAlg, const VECTOR2& pos, int type, int no); // objListに新たなOBJ2Dを追加する
};

EXTERN RankingNumManager RankingNumManager_;