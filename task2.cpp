#include <iostream>
using namespace std;

ostream &endll(ostream &stream) {
    stream << "\n" << endl;
    return stream;
}

int main() {
    cout << "Hi!" << endll;
    cout << "Hi!" << endl;
    return 0;
}
