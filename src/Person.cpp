#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
  private:
    std::string name = "mike";
    int age = 10;
  public:

    std::string getName() const {
      return name;
    }

    int getAge() const {
      return age;
    }

    std::vector<std::string> getInfo() const {
      std::vector<std::string> info;
      info.push_back(name);
      info.push_back(std::to_string(age));
      return info;
    }
};

int main() {
  Person p;
  std::vector<std::string> info = p.getInfo();
  std::cout << "Name: " << p.getName() << std::endl; // Output: Name:
  std::cout << "Age: " << p.getAge() << std::endl;   // Output: Age: 0
  std::cout << "Inf: " << info[0] << info[1] << std::endl;   // Output: Age: 0

  return 0;
}