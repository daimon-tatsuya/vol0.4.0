#pragma once
#define GARBAGE_INIT     (0)   
#define GARBAGE_MOVE     (1)
class Garbage : public OBJ2D
{
public:
    bool caughtFlg;    //true�̎������グ���Ă�
   
    VECTOR2 initVelocity;//�����x


    void init();
    void update();
    void draw(); 
    void lifted();//�����グ�邽���̃S�~�̓���
    void thrown();//���������̃S�~�̓���
  
};

EXTERN Garbage garbage;
