#include <deque>
#include <iostream>

int SumCpp11()
{
    return 0;
}

/// Variadic template for sum
template<typename T1, typename... T>
int SumCpp11( T1 s, T... ts )
{
    return s + SumCpp11( ts... );
}

/// Create an object of
/// an arbitrary type
/// from an arbitrary number of arguments
template<typename... Args>
int doSomeWork( Args... args )
{
    return ( args + ... );  // Sum fold expressions since C++17
}

/// Understand decltype (C++ 14 ?) no longer needed in C++17
template<typename Container, typename Index>
auto authAndAccess( Container&& c, Index i ) -> decltype( std::forward<Container>( c )[i] )
{
    //    authenticateUser();
    return std::forward<Container>( c )[i];
}

// Fold expressions since C++17
template<typename ...Args>
void FoldPrint(Args&&... args)
{
    (std::cout << ... << std::forward<Args>(args)) << '\n';
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    auto res = SumCpp11( 1, 2, 3 );
    std::cout << "Result: " << res << std::endl;
    auto r2 = doSomeWork( 4, 5, 6 );
    std::cout << "Result2: " << r2 << std::endl;

    // decltype
    std::deque<int> d{ 1, 2, 3 };
    int             index = 0;
    auto            r3    = authAndAccess( d, index );
    std::cout << "Result3: " << r3 << std::endl;

    FoldPrint("print ", "something ", "nice " );

    return 0;
}
