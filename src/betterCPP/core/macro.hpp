#ifndef betterCPP__core__macro
#define betterCPP__core__macro

#define to_string(a) to_string_instant(a)
#define to_string_instant(a) #a

#define glue_instant(a,b) a ## b
#define glue(a,b) glue_instant(a, b)

#define twice(x) x x

#define unused(x) (void)(x)

#define pri  private:
#define pub  public:

#endif