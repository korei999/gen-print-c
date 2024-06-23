#include "genarg.h"

int
main()
{
                                /* up to 20 args */
    fprintg(stdout, "'{}' '{}' double: {}\n", GAS(3, "this", "is", 12.5));
    fprintg(stdout, "'{}' '{}' {}: {}\n", GAS(4, "this", "is", "pointer", (void*)0xdeadbeef));

    fprintg(stdout, "each arg: {}, {}, {}\n", GA(1), GA(2.0f), GA("three"));

    /* or like this */
    COUT("{}, {}, {}, {}, {}\n", 1, 2.0f, "three", 4u, 5.0);

    /* gotta put something if no args */
    COUT("no args\n", 0);
}
