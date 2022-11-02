#include "CharCounter.h"

int main()
{
    CharCounter CC("file.txt");
    CC.find();
    //CC.print();
    CC.printInSFMML();
    return 0;
}