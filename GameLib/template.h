#ifndef INCLUDED_TEMPLATE
#define	INCLUDED_TEMPLATE

//******************************************************************************
//
//
//      �[��Singleton
//
//
//******************************************************************************

template <class T>
class Singleton
{
public:
    static T *getInstance()
    {
        static T instance;
        return &instance;
    }
};

//******************************************************************************

#endif // !INCLUDED_TEMPLATE
