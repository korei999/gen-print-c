#include "genarg.h"

int
main()
{
                                /* up to 20 args */
    printg("'{}' '{}' double: {}\n", GAS(3, "this", "is", 12.5));
    printg("'{}' '{}' {}: {}\n", GAS(4, "this", "is", "pointer", (void*)0xdeadbeef));

    printg("each arg: {}, {}, {}\n", GA(1), GA(2.0f), GA("three"));
}
