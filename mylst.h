#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <locale>
#include <codecvt>
// #include <graphics.h>
using namespace std;
// string viet_hoa(wstring s){
//     for(wchar_t &x: s) x = toupper(x);
//     return s;
// }

void draw_logo()
{
    wcout << "    _    ___   _      __     _____ ____  ___  //\\  _   _   ____  _   _   __  "<< "\n";
    wcout << "   / \\  |_ _| | |     \\_\\   |_   _|  _ \\|_ _||/_\\|| | | | |  _ \\| | | |_/_/_ "
          << "\n";
    wcout << "  / _ \\  | |  | |     /_\\     | | | |_) || || ____| | | | | |_) | |_| | | | |"
          << "\n";
    wcout << " / ___ \\ | |  | |___ / _ \\    | | |  _ < | ||  _|_| |_| | |  __/|  _  | |_| |"
          << "\n";
    wcout << "/_/   \\_\\___| |_____/_/ \\_\\   |_| |_| \\_\\___|_____|\\___/  |_|   |_| |_|\\___/ "
          << "\n";
    wcout << "                                               /\\ "
          << "\n";
    wcout << "                                               \\/"
          << "\n";
    wcout << "-----------------------------------------------------------------------------\n";
}
void tro_choi(wstring cau_hoi, wstring a, wstring b, wstring c, wstring d, wchar_t result, int flag)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    // wcin.tie(0);wcout.tie(0);
    //  wcout << "\n";
    //  wcout << "  " << draw_dong << "  " << endl;
    //  wcout << "/" << draw_khoang_trong << "\\" << endl;
    //  wcout << "/ " << draw_khoang_trong << " \\" << endl;
    //  wcout << "| "<< cau_hoi << " |"<<"\n";
    //  wcout << "\\ " << draw_khoang_trong << " /" << endl;
    //  wcout << "\\" << draw_khoang_trong << "/" << endl;
    //  wcout << "  " << draw_dong << "  " << endl;
    wcout << "          " << cau_hoi << "\n";
    wcout << L"A. " << a << "          \t" << L"B. " << b << "\n";
    wcout << L"C. " << c << "          \t" << L"D. " << d << "\n";
    wchar_t chon; wcin >> chon;
    if (toupper(chon) == toupper(result))
        wcout << L"Bạn trả lời đúng!!!\n";
        //flag = 1;
    else{
        wcout << L"Rất tiếc câu trả lời sai rồi !" << "\n";
        wcout << L"Đáp án của câu hỏi là: " << result << endl;
        flag = 0;
    }
    wcout << "-----------------------------------------------------------------------------\n";
}

wstring cau_hoi[15] = {
    L"Nhà vô địch World Cup 2022 là đội tuyển nào?",
    L"Chủ tịch Hồ Chí Minh sinh năm nào?",
    L"Chuyển đổi số 155 từ hệ thập phân sang hệ nhị phân",
    L"'Thị ơi thị rụng bị bà. Bà để bà ngửi chứ bà không ăn' là câu nói trong truyện cổ tích nào?",
    L"Không có giải thưởng Nobel nào sau đây?",
};

wstring dap_an[15][4]{
    {L"Việt Nam", L"Brazil", L"Pháp", L"Argentina"},
    {L"1969", L"1905", L"1890", L"1895"}

};

wchar_t dap_an_dung[15] = {
    L'D',
    L'C',
};