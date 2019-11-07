#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

class CaesarCipher{

  public:
  explicit CaesarCipher(const size_t cipherKey);
  explicit CaesarCipher(const std::string& cipherKey);

  std::string applyCipher(const std::string& inputText, const CipherMode cipherMode) const;

  private:
  size_t cipherKey_{0};
  const std::vector<char> alphabet_ {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize_ { alphabet_.size() };
  
};

#endif
