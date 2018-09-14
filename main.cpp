#include "Executive.h"
#include "Minesweeper.h"
int main(int argc, char* argv[])
{
    Executive exe(argv[1],argv[2],argv[3]);
    exe.run();
    return(0);
}