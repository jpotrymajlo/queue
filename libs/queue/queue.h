
#include <memory>
#include <vector>
#include <string>

namespace jp {

class queue 
{
    struct node 
    {
        std::unique_ptr<node> next;
        std::string value;
        node(std::string s) :
            value {s},
            next {nullptr}
        {
        }
    };
private:
     std::unique_ptr<node> head;
     node* tail;
public:
     queue();
     virtual ~queue();

     void push(std::string s);
     std::vector<std::string> pop();
};

}
