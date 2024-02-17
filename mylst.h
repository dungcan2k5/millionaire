#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

void draw_logo()
{
    wcout << "    _    ___   _      __     _____ ____  ___  //\\  _   _   ____  _   _   __  "
          << "\n";
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
void ket_qua(wchar_t chon, wchar_t result, int flag)
{
    // Hàm chọn kết quả và xem kết quả có đúng không
    // wchar_t chon; wcin >> chon;
    if (toupper(chon) == toupper(result))
        wcout << L"Bạn trả lời đúng!!!\n";
    else
    {
        wcout << L"Rất tiếc câu trả lời sai rồi !" << "\n";
        wcout << L"Đáp án của câu hỏi là: " << result << endl;
        flag = 0; // Nếu trả lời sai thì trò chơi dừng
    }
}
void tro_giup(int t)
{
    if (t == 2)
    {
        wcout << L"Bạn muốn gọi điện cho ai: ";
        wstring nguoi_muon_goi;
        wcin >> nguoi_muon_goi;
        wcout << "\n"
              << L"Bạn có 1 phút gọi điện!!!\n";
    }
    else if (t == 3)
    {
        wcout << L"Xin mời bạn hỏi khán giả trong trường quay";
        wcout << L"Nhập số khán giả hỏi";
        int so_luong[5] = {0};
        for (int i = 1; i <= 4; i++)
        {
            wcout << "\n"
                  << L"Mời khán giả" << i << L" cho ý kiến: ";
            wchar_t s;
            wcin >> s;
            switch (s)
            {
            case 'A':
                so_luong[1]++;
            case 'B':
                so_luong[2]++;
            case 'C':
                so_luong[3]++;
            case 'D':
                so_luong[4]++;
            }
        }
        wcout << L"Đáp án A có : " << so_luong[1] << L"lựa chọn\n";
        wcout << L"Đáp án B có : " << so_luong[2] << L"lựa chọn\n";
        wcout << L"Đáp án C có : " << so_luong[3] << L"lựa chọn\n";
        wcout << L"Đáp án D có : " << so_luong[4] << L"lựa chọn\n";
        wcout << L"Lựa chọn cuối cùng của bạn là :";
    }
    else
    {
    }
}
void in_sp(int one,int two,int three)
{
    wcout << L"Bạn còn các quyền trợ giúp là: \n";
    if (one != 0)
        wcout << L"1. Năm mươi năm mươi\n";
    if (two != 0)
        wcout << L"2. Gọi điện cho người thân\n";
    if (three != 0)
        wcout << L"3.Hỏi ý kiến khán giả\n";
}
void check_sp(int one, int two, int three)
{
    // Phần lưạ chọn đáp án hay trợ giúp ()
    wcout << L"Bạn có xử dụng quyền trợ giúp không (Có là 1 hoặc Không là 0): ";
    int yesno;
    wcin >> yesno;
    if (yesno == 1)
    {
        in_sp(one,two,three);   
        wcout << L"Bạn sẽ sẽ dụng quyền trợ giúp nào : ";
        int t;
        wcin >> t;
        switch (t){
            case 1 :
                one--;
            case 2 :
                two--;
            case 3:
                three--;
        }
        tro_giup(t);
    }
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
// Phần trợ giúp Hỏi Ý Kiến Khán Giả
void HoiKhanGia()
{
    wcout << L"Nhập số khán giả hỏi";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        wcout << "\n"
              << L"Mời khán giả" << i << L" cho ý kiến: ";
        wstring s;
        wcin >> s;
    }
}
void trogiup_nammuoi(string dap_an_dung, string dap_an_nhieu)
{
}

void in(wstring cau_hoi, wstring a, wstring b, wstring c, wstring d)
{
    // In câu hỏi và đáp án
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << "          " << cau_hoi << "\n";
    wcout << L"A. " << a << "          \t" << L"B. " << b << "\n";
    wcout << L"C. " << c << "          \t" << L"D. " << d << "\n";
}

void tro_choi(wstring cau_hoi, wstring a, wstring b, wstring c, wstring d, wchar_t result, int flag)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Mời bạn chọn đáp án:";
    wchar_t chon;
    wcin >> chon;
    if (toupper(chon) == toupper(result))
        wcout << L"Bạn trả lời đúng!!!\n";
    else
    {
        wcout << L"Rất tiếc câu trả lời sai rồi !" << "\n";
        wcout << L"Đáp án của câu hỏi là: " << result << endl;
        flag = 0; // Nếu trả lời sai thì trò chơi dừng
    }
    wcout << "-----------------------------------------------------------------------------\n";
}