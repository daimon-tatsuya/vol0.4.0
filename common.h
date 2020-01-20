#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

//******************************************************************************
//
//
//      common.h
//
//
//******************************************************************************

//------< typedef >-------------------------------------------------------------

//------< �}�N���֐� >-----------------------------------------------------------
#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}      // ���������������
#define ToRadian(x)     DirectX::XMConvertToRadians(x)  // �p�x�����W�A����

//------< �萔 >----------------------------------------------------------------
#define VEC4_WHITE      (VECTOR4(1, 1, 1, 1))   // ��

// �V�[���Ǘ��p�萔
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)
#define SCENE_OVER      (2)

#endif// ! INCLUDED_COMMON
