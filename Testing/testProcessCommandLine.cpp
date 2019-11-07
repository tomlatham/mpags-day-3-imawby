//! Unit Tests for MPAGSCipher processCommandLine interface

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessCommandLine.hpp"

// Has to be done separately, when this tag is set others are not.
TEST_CASE("Check long help tag is set", "[cmdLineArgs]"){

  //Default creation options for programSettings struct
  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./", "--help"};

  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.helpRequested == true);
  REQUIRE(processStatus == true);

}

// Has to be done separately, when this tag is set others are not.
TEST_CASE("Check short help tag is set", "[cmdLineArgs]"){

  //Default creation options for programSettings struct
  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./", "-h"};

  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.helpRequested == true);
  REQUIRE(processStatus == true);

}

// Has to be done separately, when this tag is set others are not.
TEST_CASE("Check version tag is set", "[cmdLineArgs]"){

  //Default creation options for programSettings struct
  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./", "--version"};

  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.versionRequested == true);
  REQUIRE(processStatus == true);

}

TEST_CASE("Check other tags are set", "[cmdLineArgs]"){

  //Default creation options for programSettings struct
  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./", "-i", "inputFileName", "-o", "outputFileName", "-k", "7"};

  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.inputFileName == "inputFileName");
  REQUIRE(programSettings.outputFileName == "outputFileName");
  REQUIRE(programSettings.cipherKey == "7");
  REQUIRE(processStatus == true);

}

TEST_CASE("Check encrypt is set", "[cmdLineArgs]"){

  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Decrypt};
  std::vector<std::string> cmdLineArgs{"./", "--encrypt"};
  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.cipherMode == CipherMode::Encrypt);
  REQUIRE(processStatus == true);

}

TEST_CASE("Check decrypt is set", "[cmdLineArgs]"){

  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./", "--decrypt"};
  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.cipherMode == CipherMode::Decrypt);
  REQUIRE(processStatus == true);

}

TEST_CASE("Check identity", "[cmdLineArgs]"){

  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs{"./"};
  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE(programSettings.helpRequested == false);
  REQUIRE(programSettings.versionRequested == false);
  REQUIRE(programSettings.inputFileName.empty() == true);
  REQUIRE(programSettings.outputFileName.empty() == true);
  REQUIRE(programSettings.cipherKey == "0");
  REQUIRE(programSettings.cipherMode == CipherMode::Encrypt);
  REQUIRE(processStatus == true);

}

// Example of testing for error conditions
TEST_CASE("Key entered with no key specified", "[cmdLineArgs]"){
  
  ProgramSettings programSettings{false, false, "", "", "0", CipherMode::Encrypt};
  std::vector<std::string> cmdLineArgs = {"./", "-k"};
  bool processStatus{processCommandLine(cmdLineArgs, programSettings)};

  REQUIRE( processStatus == false );
}
