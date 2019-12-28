#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg = false;    //true�̎������グ���Ă�

    bool throwFlg = false;

    VECTOR2 initVelocity;//�����x


    void init();
    void update();
    void draw(); 
    void lifted();//�����グ�邽���̃S�~�̓���
    void thrown();//���������̃S�~�̓���
  
};

extern Garbage garbage;
