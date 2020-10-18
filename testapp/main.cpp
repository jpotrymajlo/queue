#include "queue/queue.h"
#include "input/input.h"
#include "obfuscator/obfuscator.h"
#include "obfuscator/rot13.h"


int main(int argc, char* argv[]){
    jp::Queue<std::string> queue;
    jp::Rot13 rot13;
    jp::Obfuscator obfuscator {queue, rot13};
    jp::Input input {queue};
    // wait until all data are read from the input
    input.waitUntilFinished();

    // Now objects can be destructed. 
    // Obfuscator destructor will wait until all data are proceeded

    return 0;
}
