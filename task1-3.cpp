#include <iostream>
#include <string>

using namespace std;

template <class T>
class Pair1 {
private:
    T m_first;
    T m_second;
public:
    Pair1(T first, T second) : m_first(first), m_second(second) {}

    const T first() const {return m_first;}
    const T second() const {return m_second;}

};

template< typename T, typename S >
class Pair {
private:
    T m_first;
    S m_second;
public:
    Pair(T first, S second) : m_first(first), m_second(second) {}

    const T first() const {return m_first;}
    const S second() const {return m_second;}
};

template <class U>
class StringValuePair : public Pair<string, U> {
public:
    StringValuePair(string str, U value) : Pair<string, U>(str, value) {}
};


int main() {
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << endl;

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << endl;

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

return 0;
}
