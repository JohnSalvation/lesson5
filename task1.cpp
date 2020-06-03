#include <iostream>
using namespace std;

class Integer {
private:
    int m_number;
public:
    Integer() {}
    friend istream& operator >> (istream &in, Integer &integer);
    friend ostream& operator << (ostream &out, const Integer &integer);

    ~Integer() {}
};

istream& operator >> (istream &in, Integer &integer) {
    in >> integer.m_number;
    return in;
}

ostream& operator << (ostream &out, const Integer &integer) {
    out << "Number: " << integer.m_number << endl;
    return out;
}

void fix_cin() {
    cin.clear();
    while (cin.get() != '\n');
}

int main() {
    Integer num;
    cout << "Enter an integer: ";
    do {
        cin >> num;
        if(!cin){
            fix_cin();
            cerr << "Error! \nEnter an integer: ";
        }
        else
            break;
    } while(true);
    cout << num;

    return 0;
}
