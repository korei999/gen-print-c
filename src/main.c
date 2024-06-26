#include "logs.h"

int
main()
{
                                /* up to 20 args */
    fprintg(stdout, "'{}' '{}' double: {}\n", GAS(3, "this", "is", 12.5));
    fprintg(stdout, "'{}' '{}' {}: {}\n", GAS(4, "this", "is", "pointer", (void*)0xdeadbeef));

    fprintg(stdout, "each arg: {}, {}, {}\n", GA(1), GA(2.0f), GA("three"));

    /* or like this */
    COUT("{}, {}, {}, {}, {}\n", 1, 2.0f, "three", 4u, 5.0);

    COUT("{}, {}, {}\n", 1, 2, "three");
    CERR("asdf\n");
    CERR("any arg: {}, {}, {}\n", "any", (void*)0xa68, 123UL);

    LOG_OK("no args: works\n");
    const char* works = "works";
    LOG_OK("{} {}\n", "still", works);

    const char* what = "what?";
    COUT("{}, {}, {}, {}, {}\n", 1, 2.2, 3.3f, "four", what);
}
