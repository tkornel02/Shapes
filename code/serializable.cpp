#include "serializable.h"

std::istream& operator>>(std::istream& is, Serializable& s)
{
    s.read(is);
    return is;
}
