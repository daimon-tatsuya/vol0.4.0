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
    readData();
    result[5] = combNum[0];
    for (int i = 0; i < RESULT_MAX; i++)
    {
        KetaCount[i] = 0;
    }

    pos = VECTOR2(730, 215);

    //並び替え
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
}

void Ranking::update()
{
    
    if (TRG(0) & PAD_TRG2)
    {
        nextScene = SCENE_TITLE;
        writeData();        
    }
}

void Ranking::draw()
{
    bg.draw();

    conveyor.draw();

    ber.draw();

    pos = VECTOR2(430, 215);

    for (int i = 0; i < RESULT_MAX - 1; i++)//順位描画
    {
        data = &sprComb[i + 1];
        data->draw(pos);
        pos.y += 95;
    }
    pos.y = 215;
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

void Ranking::KetaCountMove()//桁をカウントする。
{    
    for (int i = 0; i < RESULT_MAX; i++)
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