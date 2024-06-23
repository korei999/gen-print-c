#pragma once

#include <stdarg.h>
#include <stdio.h>

#define GA_NEW(TAG, VAL) (GenArg){.tag = TAG, .data.TAG = {VAL}}

#define GA(A)                                                                                                          \
    _Generic((A),                                                                                                      \
        char: GenArgChar,                                                                                              \
        int: GenArgInt,                                                                                                \
        long: GenArgLong,                                                                                              \
        size_t: GenArgSizeT,                                                                                           \
        float: GenArgFloat,                                                                                            \
        double: GenArgDouble,                                                                                          \
        char*: GenArgPChar,                                                                                            \
        void*: GenArgPVoid)(A)

/* dumbest shit but works */
#define __ADD_GA1(x, ...) GA(x)
#define __ADD_GA2(x, ...) GA(x), __ADD_GA1(__VA_ARGS__)
#define __ADD_GA3(x, ...) GA(x), __ADD_GA2(__VA_ARGS__)
#define __ADD_GA4(x, ...) GA(x), __ADD_GA3(__VA_ARGS__)
#define __ADD_GA5(x, ...) GA(x), __ADD_GA4(__VA_ARGS__)
#define __ADD_GA6(x, ...) GA(x), __ADD_GA5(__VA_ARGS__)
#define __ADD_GA7(x, ...) GA(x), __ADD_GA6(__VA_ARGS__)
#define __ADD_GA8(x, ...) GA(x), __ADD_GA7(__VA_ARGS__)
#define __ADD_GA9(x, ...) GA(x), __ADD_GA8(__VA_ARGS__)
#define __ADD_GA10(x, ...) GA(x), __ADD_GA9(__VA_ARGS__)
#define __ADD_GA11(x, ...) GA(x), __ADD_GA10(__VA_ARGS__)
#define __ADD_GA12(x, ...) GA(x), __ADD_GA11(__VA_ARGS__)
#define __ADD_GA13(x, ...) GA(x), __ADD_GA12(__VA_ARGS__)
#define __ADD_GA14(x, ...) GA(x), __ADD_GA13(__VA_ARGS__)
#define __ADD_GA15(x, ...) GA(x), __ADD_GA14(__VA_ARGS__)
#define __ADD_GA16(x, ...) GA(x), __ADD_GA15(__VA_ARGS__)
#define __ADD_GA17(x, ...) GA(x), __ADD_GA16(__VA_ARGS__)
#define __ADD_GA18(x, ...) GA(x), __ADD_GA17(__VA_ARGS__)
#define __ADD_GA19(x, ...) GA(x), __ADD_GA18(__VA_ARGS__)
#define __ADD_GA20(x, ...) GA(x), __ADD_GA19(__VA_ARGS__)
#define __ADD_GA(i, ...) __ADD_GA##i(__VA_ARGS__)
#define GAS(count, ...) __ADD_GA(count, __VA_ARGS__)

typedef struct GenArg
{
    enum
    {
        GA_CHAR,
        GA_INT,
        GA_LONG,
        GA_SIZE_T,
        GA_FLOAT,
        GA_DOUBLE,
        GA_PCHAR,
        GA_PVOID
    } tag;
    union
    {
        struct GA_CHAR { char c; } GA_CHAR;
        struct GA_INT { int i; } GA_INT;
        struct GA_LONG { long l; } GA_LONG;
        struct GA_SIZE_T { size_t s; } GA_SIZE_T;
        struct GA_FLOAT { float f; } GA_FLOAT;
        struct GA_DOUBLE { double d; } GA_DOUBLE;
        struct GA_PCHAR { char* p; } GA_PCHAR;
        struct GA_PVOID { char* v; } GA_PVOID;
    } data;
} GenArg;

static inline GenArg
GenArgChar(char c)
{
    return GA_NEW(GA_CHAR, c);
}

static inline GenArg
GenArgInt(int i)
{
    return GA_NEW(GA_INT, i);
}

static inline GenArg
GenArgLong(long l)
{
    return GA_NEW(GA_LONG, l);
}

static inline GenArg
GenArgSizeT(size_t s)
{
    return GA_NEW(GA_SIZE_T, s);
}

static inline GenArg
GenArgFloat(float f)
{
    return GA_NEW(GA_FLOAT, f);
}

static inline GenArg
GenArgDouble(double d)
{
    return GA_NEW(GA_DOUBLE, d);
}

static inline GenArg
GenArgPChar(char* p)
{
    return GA_NEW(GA_PCHAR, p);
}

static inline GenArg
GenArgPVoid(void* v)
{
    return GA_NEW(GA_PVOID, v);
}

static inline void
printg(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    for (size_t pos = 0; fmt[pos]; pos++)
    {
        /* TODO: parse formatting 'args' like digits after dot etc... */
        if (fmt[pos] == '{' && fmt[pos + 1] && fmt[pos + 1] == '}')
        {
            GenArg ga = va_arg(args, GenArg);
            switch (ga.tag)
            {
                default:
                    printf("unhandled type");
                    break;

                case GA_CHAR:
                    printf("%c", ga.data.GA_CHAR.c);
                    break;

                case GA_INT:
                    printf("%d", ga.data.GA_INT.i);
                    break;

                case GA_LONG:
                    printf("%ld", ga.data.GA_LONG.l);
                    break;

                case GA_SIZE_T:
                    printf("%zu", ga.data.GA_SIZE_T.s);
                    break;

                case GA_FLOAT:
                    printf("%f", ga.data.GA_FLOAT.f);
                    break;

                case GA_DOUBLE:
                    printf("%lf", ga.data.GA_DOUBLE.d);
                    break;

                case GA_PCHAR:
                    printf("%s", ga.data.GA_PCHAR.p);
                    break;

                case GA_PVOID:
                    printf("%p", ga.data.GA_PVOID.v);
                    break;
            }
            pos++;
        }
        else
        {
            putchar(fmt[pos]);
        }
    }

    va_end(args);
}
