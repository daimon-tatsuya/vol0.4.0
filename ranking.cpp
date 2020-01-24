#define   _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "all.h"

extern int nextScene;

//FILE* fp;

void Ranking::init()
{
    state = 0;
    readData();
    result[5] = combNum[0];
    for (int i = 0; i < RESULT_MAX; i++)
    {
        KetaCount[i] = 0;
    }

    pos = VECTOR2(730, 215);

    //•À‚Ñ‘Ö‚¦
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (result[i] < result[i + j])
            {
                copy = result[i];
                result[i] = result[i + j];
                result[i + j] = copy;
            }
            //if (result[i].score == result[i + j].score && result[i].score > result[i + j].score)
            //{
            //    copy = result[i];
            //    result[i] = result[i + j];
            //    result[i + j] = copy;
            //}
        }
    }

    KetaCountMove();

    for (int i = 0; i < RESULT_MAX - 1; i++)
    {
        for (int j = 0; j < KetaCount[i]; j++)
        {
            RankingNumManager_.add(&rankingNum, VECTOR2(pos.x, pos.y), j, i);
        }
        pos.y += 95;
    }    

    shutter.init();
}

void Ranking::update()
{
    switch (state)
    {
    case 0:

        if (TRG(0) & PAD_TRG2)
        {
            state++;            
            writeData();
        }
        break;

    case 1:

        if (shutter.scrollDown()) { nextScene = SCENE_TITLE; }

        break;
    }
    
}

void Ranking::draw()
{
    // ‰æ–Ê‚ð”’‚Å“h‚è‚Â‚Ô‚·
    GameLib::clear(1, 1, 1);

    bg.draw();
    conveyor.draw();
    //ber.draw();

    data = &sprRanking;
    data->draw(VECTOR2(330, 0), VECTOR2(0.8f, 0.8f));

    pos = VECTOR2(430, 215);

    for (int i = 0; i < RESULT_MAX - 1; i++)//‡ˆÊ•`‰æ
    {
        data = &sprComb[i + 1];
        data->draw(pos);
        pos.y += 95;
    }
    pos.y = 215;

    RankingNumManager_.draw();

    shutter.draw();
}

void Ranking::end()
{

}

void Ranking::readData()
{
    FILE* fp;

    if ((fopen_s(&fp, "saveData1.dat", "rb")) == 0)
    {
        fread(&result, sizeof(int), RESULT_MAX - 1, fp);
        fclose(fp);
    }
    else
    {
        fopen_s(&fp, "saveData1.dat", "wb");
        fwrite(&result, sizeof(int), RESULT_MAX - 1, fp);
        fclose(fp);
    }
    //    //std::ifstream ifs(fileName);
    //    //
    //    //assert(ifs);
    //    //
    //    //int a;
    //    //ifs >> a;
}

void Ranking::writeData()
{   
    FILE* fp;

    fopen_s(&fp, "saveData1.dat", "wt");

    fwrite(&result, sizeof(int), RESULT_MAX - 1, fp);
    fclose(fp);

    //std::ofstream ofs("saveData1.txt");
    //assert(ofs);
    //for (int i = 0; i < RESULT_MAX; i++)
    //{
    //    ofs << data[i];
    //}
}

void Ranking::KetaCountMove()//Œ…‚ðƒJƒEƒ“ƒg‚·‚éB
{    
    for (int i = 0; i < RESULT_MAX + 1; i++)
    {
        int kari = result[i] / 10;
        KetaCount[i]++;

        while (1)
        {
            if (kari == 0) { break; }
            kari /= 10;
            KetaCount[i]++;
        }        
    }
}