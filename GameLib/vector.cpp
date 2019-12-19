//******************************************************************************
//
//
//      Vector
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "Vector.h"

//******************************************************************************
//
//      Vector2
//
//******************************************************************************

//--------------------------------
//  =
//--------------------------------
VECTOR2 &VECTOR2::operator=(const VECTOR2& v)
{
    x = v.x; y = v.y; return *this;
}

//--------------------------------
//  +=
//--------------------------------
VECTOR2 &VECTOR2::operator+=(const VECTOR2 &v)
{
    x += v.x;
    y += v.y;
    return *this;
}

//--------------------------------
//  -=
//--------------------------------
VECTOR2 &VECTOR2::operator-=(const VECTOR2 &v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

//--------------------------------
//  *=
//--------------------------------
VECTOR2 &VECTOR2::operator*=(float f)
{
    x *= f;
    y *= f;
    return *this;
}

//--------------------------------
//  /=
//--------------------------------
VECTOR2 &VECTOR2::operator/=(float f)
{
    x /= f;
    y /= f;
    return *this;
}

//--------------------------------
//  +�i�����j
//--------------------------------
VECTOR2 VECTOR2::operator+() const
{
    return VECTOR2(x, y);
}

//--------------------------------
//  -�i�����j
//--------------------------------
VECTOR2 VECTOR2::operator-() const
{
    return VECTOR2(-x, -y);
}

//--------------------------------
//  +�i�a�j
//--------------------------------
VECTOR2 VECTOR2::operator+(const VECTOR2 &v) const
{
    return VECTOR2(x + v.x, y + v.y);
}

//--------------------------------
//  -�i���j
//--------------------------------
VECTOR2 VECTOR2::operator-(const VECTOR2 &v) const
{
    return VECTOR2(x - v.x, y - v.y);
}

//--------------------------------
//  *
//--------------------------------
VECTOR2 VECTOR2::operator*(float f) const
{
    return VECTOR2(x * f, y * f);
}

//--------------------------------
//  *
//--------------------------------
VECTOR2 operator*(float f, const VECTOR2 &v)
{
    return VECTOR2(v.x * f, v.y * f);
}

//--------------------------------
//  /
//--------------------------------
VECTOR2 VECTOR2::operator/(float f) const
{
    return VECTOR2(x / f, y / f);
}

//--------------------------------
//  ==
//--------------------------------
bool VECTOR2::operator == (const VECTOR2& v) const
{
    return (x == v.x) && (y == v.y);
}

//--------------------------------
//  !=
//--------------------------------
bool VECTOR2::operator != (const VECTOR2& v) const
{
    return (x != v.x) || (y != v.y);
}

//--------------------------------
//  ������2����擾
//--------------------------------
float vec2LengthSq(const VECTOR2& v)
{
    return v.x * v.x + v.y * v.y;
}

//--------------------------------
//  �������擾
//--------------------------------
float vec2Length(const VECTOR2& v)
{
    return sqrtf(vec2LengthSq(v));
}

//--------------------------------
//  ������1�ɂ���
//--------------------------------
VECTOR2* vec2Normalize(const VECTOR2& v, VECTOR2* out)
{
    *out = v;
    float d = vec2Length(v);
    if (d < FLT_EPSILON) return out;
    *out /= d;
    return out;
}

//******************************************************************************
//
//      Vector3
//
//******************************************************************************

//--------------------------------
//  =
//--------------------------------
VECTOR3 &VECTOR3::operator=(const VECTOR3& v)
{
    x = v.x;
    y = v.y;
    return *this;
}

//--------------------------------
//  +=
//--------------------------------
VECTOR3 &VECTOR3::operator+=(const VECTOR3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

//--------------------------------
//  -=
//--------------------------------
VECTOR3 &VECTOR3::operator-=(const VECTOR3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

//--------------------------------
//  *=
//--------------------------------
VECTOR3 &VECTOR3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

//--------------------------------
//  /=
//--------------------------------
VECTOR3 &VECTOR3::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

//--------------------------------
//  +�i�����j
//--------------------------------
VECTOR3 VECTOR3::operator+() const
{
    return VECTOR3(x, y, z);
}

//--------------------------------
//  -�i�����j
//--------------------------------
VECTOR3 VECTOR3::operator-() const
{
    return VECTOR3(-x, -y, -z);
}

//--------------------------------
//  +�i�a�j
//--------------------------------
VECTOR3 VECTOR3::operator+(const VECTOR3 &v) const
{
    return VECTOR3(x + v.x, y + v.y, z + v.z);
}

//--------------------------------
//  -�i���j
//--------------------------------
VECTOR3 VECTOR3::operator-(const VECTOR3 &v) const
{
    return VECTOR3(x - v.x, y - v.y, z - v.z);
}

//--------------------------------
//  *
//--------------------------------
VECTOR3 VECTOR3::operator*(float f) const
{
    return VECTOR3(x * f, y * f, z * f);
}

//--------------------------------
//  *
//--------------------------------
VECTOR3 operator*(float f, const VECTOR3 &v)
{
    return VECTOR3(v.x * f, v.y * f, v.z * f);
}

//--------------------------------
//  /
//--------------------------------
VECTOR3 VECTOR3::operator/(float f) const
{
    return VECTOR3(x / f, y / f, z / f);
}

//--------------------------------
//  ==
//--------------------------------
bool VECTOR3::operator == (const VECTOR3& v) const
{
    return (x == v.x) && (y == v.y) && (z == v.z);
}

//--------------------------------
//  !=
//--------------------------------
bool VECTOR3::operator != (const VECTOR3& v) const
{
    return (x != v.x) || (y != v.y) || (z != v.z);
}

//******************************************************************************
