#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <regex>
#include <iterator>

using namespace std;

int main() {
    setlocale(0, "");

    string str;
    ifstream in;
    in.open("yandex.txt");
    getline(in, str, '\0');
    in.close();

    cmatch result;
    regex regular_currency("(>)([A-Z]{3})(<)");
    regex regular_price("(>)([6-9]{1}[0-9]{1})([,])([0-9]{2})(<)");

    auto words_begin_currency = sregex_iterator(str.begin(), str.end(), regular_currency);
    auto words_begin_price = sregex_iterator(str.begin(), str.end(), regular_price);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin_currency, j = words_begin_price;
         i != words_end, j != words_end; ++i, ++j) {
        smatch match_currency = *i;
        smatch match_price = *i;
        string match_str_currency = match_currency.str();
        string match_str_price = match_price.str();
        cout << match_str_currency << match_str_price << '\n';
    }

    regex regular_link("(https?:\\/\\/)?([\\w-]{6,6}([.])[\\w-]{1,32})[^\\s]{29}([.])(rss)");
        if (regex_search(str.c_str(), result, regular_link)) {
            cout << result[0] << endl;
        }
        else
            cout << "False" << endl;

    regex regular_title("[А-яа-я]{7}\\s[А-яа-я]{7}");
    if (regex_search(str.c_str(), result, regular_title)) {
        cout << result[0] << endl;
    }
    else
        cout << "False" << endl;

    regex regular_news("([А-яа-я]{1,}\\s){7,}([А-яа-я]{1,}(?=&))");

    auto words_begin_news = sregex_iterator(str.begin(), str.end(), regular_news);
    for (sregex_iterator i = words_begin_news; i != words_end; ++i) {
        smatch match_news = *i;
        string match_str_news = match_news.str();
        cout << match_str_news << '\n';
    }

    return 0;
}

