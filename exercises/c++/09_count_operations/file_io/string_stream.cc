#include <fstream>
#include <sstream>

int main() {
  //we want to create a file whose name is changing
  std::string base_name{"file_"};
  for (auto i = 0; i < 10; ++i) {
    std::stringstream ss; //defined in header sstream
    //we create a string that is the base name
    //with the for we construct the stringstream

    ss << base_name << i << ".txt";
    std::ofstream f{ss.str()};
    //we call the ctor
    //it returns a string
    f << i << std::endl;
  }

  return 0;
}
