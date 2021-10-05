#pragma once

template <typename T>
class Sort
{
protected:
    void swap(T *xp, T *yp)
    {
        T temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

public:
    virtual void operator()(T *arr, int n) = 0;
};
