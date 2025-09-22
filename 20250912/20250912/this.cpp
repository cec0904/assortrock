#include <iostream>
#include <string>

using namespace std;




class Student {
    string name;
public:
    Student(string n) : name(n) {}
    void introduce() {
        cout << "나는 " << this->name << "야!" << endl;
    }
};

int main() {
    Student a("철수");
    Student b("영희");

    a.introduce(); // 나는 철수야!
    b.introduce(); // 나는 영희야!
}