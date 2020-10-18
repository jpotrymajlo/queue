#include "rot13.h"

namespace jp
{

void Rot13::encode(std::string & s)
{
    for (size_t i=0; i<=s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] - 'a' + 13) % 26;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] - 'A' + 13) % 26;
        }
    }
}


}