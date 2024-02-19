#include <iostream> // Nhập xuất console
#include <fstream>  // Nhập xuất file
#include <fcntl.h>  // _setmode và _O_U16TEXT
#include <windows.h>
#include <stdlib.h> // Hàm exit()
#include <locale> // 2 thư viện dưới dùng để in tiếng Việt từ file
#include <codecvt>
#include <conio.h>

#include "game.h"

using namespace std;

/**
 * \brief Vẽ logo game
 * \param path_to_file Đường dẫn tới file logo
 */
void printLogo(string path_to_file)
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

void delLine(int lineStart, int numLine)
{
    for (int i = (lineStart+numLine); i >= 0; i--)
    {
        cout << "\33[2K";
        cout << "\33[A";
    }
    
}

/**
 * \brief Màn hình chào của game
 */
void welcomeScreen()
{
    printLogo("logo.txt");
    wcout << L"\n\t\t\t\t\t\t\tVUI LÒNG LỰA CHỌN CHẾ ĐỘ\n\n";
    wcout << L"\t\t\t\t\t\t\t    [1] Chơi mới\n";
    wcout << L"\t\t\t\t\t\t\t    [2] Hướng dẫn\n";
    wcout << L"\t\t\t\t\t\t\t    [3] Bảng xếp hạng\n";
    wcout << L"\t\t\t\t\t\t\t    [4] Thông tin\n";
    wcout << L"\t\t\t\t\t\t\t    [5] Thoát trò chơi\n";
}

void showGuide()
{
    return;
}

void showRank()
{
    return;
}

void showAbout()
{
    
    
}

/// @brief Lựa chọn chế độ chơi
void choiceMode()
{
    wchar_t key;
    re_input_key:
    key = getch();

    switch (key)
    {
    case '1':
        delLine(1, 6);
        startGame();
        break;
    case '2':
        showGuide();
        break;
    case '3':
        showRank();
        break;
    case '4':
        showAbout();
        break;
    case '5':
        wcout << L"Xin chào và hẹn gặp lại!!!";
        Sleep(1500);
        exit(0);
        break;
    default:
        wcout << L"Yêu cầu bạn vừa chọn KHÔNG hợp lệ. Vui lòng chọn lại.\n";
        goto re_input_key;
        break;
    }
}
