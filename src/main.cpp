/**
 * @brief
 */

#include <fmt/core.h>

#include "ParameterPacks.h"
#include "PrintPack.h"

#include <deque>
#include <iostream>

using namespace Pack;

/**
 * @brief Base case.
 *
 * @return
 */
int
variadicSum11()
{
  return 0;
}

/// Variadic template for sum
template <typename T1, typename... T>
int
variadicSum11(T1 s, T... ts)
{
  return s + variadicSum11(ts...);
}

/// Create an object of
/// an arbitrary type
/// from an arbitrary number of arguments
template <typename... Args>
int
variadicSum17(Args... args)
{
  return (args + ...);  // Sum fold expressions since C++17
}

/// Understand decltype (C++ 14 ?) no longer needed in C++17
template <typename Container, typename Index>
auto
getFromCollection(Container&& container, Index index) -> decltype(std::forward<Container>(container)[index])
{
  //    authenticateUser();
  return std::forward<Container>(container)[index];
}

// Fold expressions since C++17
template <typename... ArgsType>
void
printFoldExpression(ArgsType&&... args)
{
  (std::cout << ... << std::forward<ArgsType>(args)) << '\n';
}

int
main()
{
  std::cout << "Hello, World!" << std::endl;

  const auto            sum11Result = variadicSum11(1, 2, 3);
  const auto            sum17Result = variadicSum17(4, 5, 6);
  const std::deque<int> numbers{ 1, 2, 3 };
  const std::uint32_t   index = 1;
  const auto            item  = getFromCollection(numbers, index);

  std::cout << "Sum result with c++11: " << sum11Result << std::endl;
  std::cout << "Sum result with c++17: " << sum17Result << std::endl;
  std::cout << "Item '" << index << "': " << item << std::endl;

  printFoldExpression("print ", "something ", "nice ");

  auto result  = composeMessage20("message %1 %2 %3", "one", "two", "three");
  auto result2 = composeMessage11("message %1 %2 %3", "one", "two", "three");

  fmt::print("The results are: \n{}\n{}\n", result, result2);

  printPack("message %1 %2 %3", "one", "two", "three");

  return 0;
}
