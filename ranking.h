#pragma once

class Ranking : public UI
{
public:
    void  move(OBJ2D*);
};

//EXTERN Ranking ranking;

class RankingErase : public EraseAlg
{
public:
    void erase(OBJ2D* obj);
};

//EXTERN RankingErase rankingErase;

class RankingManager : public OBJ2DManager
{

};

//EXTERN RankingManager RankingManager_;