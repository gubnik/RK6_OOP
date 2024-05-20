#include "../bits/field.hpp"

using namespace chess;

bool field::move (field T)
{
    if (T.TypePtr && TypePtr->attack(*this, T))
    {
        return true;
    }
    return TypePtr->move(*this, T);
}

loc_t field::x () { return X; }
loc_t field::y () { return Y; }
