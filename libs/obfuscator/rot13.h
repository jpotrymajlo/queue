#ifndef __ROT13_H__
#define __ROT13_H__

#include "encoder.h"
namespace jp 
{

class Rot13 : public Encoder
{
public:
    Rot13() = default;
    virtual ~Rot13() = default;
    void encode(std::string &);
};

}

#endif