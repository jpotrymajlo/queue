#include <iostream>
#include <chrono>
#include "queue/queue.h"
#include "input/input.h"
#include "obfuscator/obfuscator.h"
#include "obfuscator/rot13.h"

int main(int argc, char* argv[]){
    jp::Queue queue;
    jp::Rot13 rot13;
    jp::Obfuscator obfuscator {queue, rot13};
    jp::Input input {queue};

    return 0;
}
