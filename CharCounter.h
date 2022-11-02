#include<map>
#include <string>


class CharCounter
{
    std::map<char, int> mapOfChar;
    const std::string& fileName; 

public:
    CharCounter();
    explicit CharCounter(const std::string& );
    void find();
    void print() const;
    void printInSFMML() ;
    float lengthOfNumber(int);
};