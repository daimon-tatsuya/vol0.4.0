
#ifndef INCLUDED_JUDGE
#define INCLUDED_JUDGE

//******************************************************************************
//
//
//      judge.h
//
//
//******************************************************************************

//------< �萔 >----------------------------------------------------------------

//------< �\���� >---------------------------------------------------------------

//------< �v���g�^�C�v�錾 >-----------------------------------------------------
void judge();
float vector2LengthSq(VECTOR2);
float vector2Length(VECTOR2);
BOOL circleHitCheck(VECTOR2 v1, float r1, VECTOR2 v2, float r2);
BOOL rectHitCheck(VECTOR2 v1, float width1, float height1, VECTOR2 v2, float width2, float height2);


#endif // !INCLUDED_JUDGE
