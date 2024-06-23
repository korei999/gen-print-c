#include "genarg.h"

int
main()
{
                                /* up to 20 args */
    printg("'{}' '{}' double: {}\n", GARGS(3, "this", "is", 12.5));
    printg("'{}' '{}' {}: {}\n", GARGS(4, "this", "is", "pointer", (void*)0xdeadbeef));
}
