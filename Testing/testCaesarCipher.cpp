//! Unit Tests for MPAGSCipher caesarCipher interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CaesarCipher.hpp"

TEST_CASE("Caesar cipher works with key < 26", "[cipher]"){

  CaesarCipher cipher{3};

  REQUIRE(cipher.applyCipher("ABCDEFGHIJKLMNOPQRSTUVWXYZ", CipherMode::Encrypt) == "DEFGHIJKLMNOPQRSTUVWXYZABC");
  REQUIRE(cipher.applyCipher("ABCDEFGHIJKLMNOPQRSTUVWXYZ", CipherMode::Decrypt) == "XYZABCDEFGHIJKLMNOPQRSTUVW");

}

TEST_CASE("Cipher works with key = 26 i.e. loop around cases", "[cipher]"){

  CaesarCipher cipher{26};
  std::string inputString{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  REQUIRE(cipher.applyCipher(inputString, CipherMode::Encrypt) == inputString);
  REQUIRE(cipher.applyCipher(inputString, CipherMode::Decrypt) == inputString);

}

TEST_CASE("Identity transformation", "[cipher]") {

  CaesarCipher cipher{0};
  std::string inputString{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  REQUIRE(cipher.applyCipher(inputString, CipherMode::Encrypt) == inputString);
  REQUIRE(cipher.applyCipher(inputString, CipherMode::Decrypt) == inputString);

}
