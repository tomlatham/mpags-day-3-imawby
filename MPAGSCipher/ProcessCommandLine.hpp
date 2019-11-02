#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"


struct ProgramSettings{

  bool helpRequested;
  bool versionRequested;
  std::string inputFileName;
  std::string outputFileName;
  std::string cipherKey;
  CipherMode cipherMode;

};


bool processCommandLine(const std::vector<std::string>& args, ProgramSettings& programSettings);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
