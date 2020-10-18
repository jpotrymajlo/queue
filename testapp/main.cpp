#include <iostream>
#include "queue/queue.h"
#include "input/input.h"
#include "obfuscator/obfuscator.h"

int main(int argc, char* argv[]){
    jp::Queue queue;
    jp::Obfuscator obfuscator {queue};
    jp::Input input {queue};

    return 0;
}
