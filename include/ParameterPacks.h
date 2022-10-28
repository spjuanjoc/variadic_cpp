/**
 * @brief
 *
 * @author  spjuanjoc
 * @date    2022-10-28
 */

#ifndef PARAMETERPACKS_H
#define PARAMETERPACKS_H

#include <fmt/format.h>

#include <vector>
#include <string>

namespace Pack
{

/**
 * @brief
 * @tparam ArgumentsType
 * @param message
 * @param foldArguments
 * @return
 */
template <typename... ArgumentsType>
std::string
composeMessage20(const std::string& message, ArgumentsType... foldArguments)
{
  std::vector<std::string> arguments;

  (arguments.push_back(foldArguments), ...);

  std::string result(message);

  for (auto&& argument : arguments)
  {
    result.append(" ");
    result.append(argument);
  }

  return result;
}

template <typename... ArgumentsType>
std::string
composeMessage11(const std::string& message, ArgumentsType... foldArguments)
{
  std::vector<std::string> arguments;

  std::initializer_list<const char*> range = { foldArguments... };

  for (const char* const* argument = range.begin(); argument != range.end(); ++argument)
  {
    arguments.emplace_back(*argument);
  }

  //  for (auto&& arg : range)
  //    arguments.push_back(arg);

  std::string result(message);

  for (auto&& argument : arguments)
  {
    result.append(" ");
    result.append(argument);
  }

  return result;
}

}

#endif /* PARAMETERPACKS_H */
