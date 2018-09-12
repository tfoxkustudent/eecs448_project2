#include "Executive.h"
#include <time.h>
int main(int argc, char* argv[])
{


Executive exec(argv[1],argv[2],argv[3]);
exec.run();
return(0);
}
