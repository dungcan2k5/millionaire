#include <iostream> // Nhập xuất console
#include <fstream>  // Nhập xuất file
#include <fcntl.h>  // _setmode và _O_U16TEXT

#include <locale>   // 2 thư viện dưới dùng để in tiếng Việt từ file
#include <codecvt>

using namespace std;

void print_logo(string path_to_file)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    locale loc(locale(), new codecvt_utf8<wchar_t>);

    wfstream input(path_to_file);
    input.imbue(loc);
    wstring str;

    while (!input.eof())
    {
        getline(input, str);
        wcout << str << '\n';
    }
}