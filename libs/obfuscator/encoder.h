#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <string>

namespace jp 
{

class Encoder 
{
public:
    virtual ~Encoder() = default;
    virtual void encode(std::string &) = 0;
};

}


#endif