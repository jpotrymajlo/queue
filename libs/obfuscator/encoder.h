#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <string>

namespace jp 
{
/* Interface class for objects encrypting data. */
class Encoder 
{
public:
    virtual ~Encoder() = default;
    /* Encoding data. Result is in the same variable passed
     * as a parameter
     */
    virtual void encode(std::string &) = 0;
};

}


#endif