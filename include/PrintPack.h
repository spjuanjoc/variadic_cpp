/**
 * @brief
 *
 * @author  spjuanjoc
 * @date    2022-10-28
 */

#ifndef INCLUDE_PRINTPACK_H
#define INCLUDE_PRINTPACK_H

#include <iostream>

namespace Pack
{

/**
 * @brief Función base.
 *
 * @param formato
 */
void
printPack(const char* formato)
{
  std::cout << formato;
}

/**
 * @brief Función variádica recursiva.
 *
 * @tparam T
 * @tparam Targs
 * @param formato
 * @param valor
 * @param Fargs
 */
template <typename T, typename... Targs>
void
printPack(const char* formato, T valor, Targs... Fargs)
{
  for (; *formato != '\0'; formato++)
  {
    if (*formato == '%')
    {
      std::cout << valor;
      printPack(formato + 1, Fargs...);  // llamada recursiva
      return;
    }
    std::cout << *formato;
  }
}

}

#endif /* INCLUDE_PRINTPACK_H */
