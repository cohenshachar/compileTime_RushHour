#ifndef HW5_UTILITIES_H
#define HW5_UTILITIES_H


template<bool expression, typename T, typename F>
struct Conditional{
    typedef T value;
};

template<typename T, typename F>
struct Conditional<false, T, F>{
    typedef F value;
};

template<bool expression, int T, int F>
struct ConditionalInteger{
    constexpr static int value = T;
};

template<int T, int F>
struct ConditionalInteger<false, T, F>{
    constexpr static int value = F;
};



#endif //HW5_UTILITIES_H
