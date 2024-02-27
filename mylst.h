#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <locale>
#include <codecvt>
#include <random>

using namespace std;

wstring cau_hoi[15];
wstring dap_an[15][4];
wchar_t dap_an_dung[15];

void inputQuestion(string path_to_file)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    wfstream input(path_to_file);
    input.imbue(loc);

    wstring data;
    for (int i = 0; i < 15; i++)
    {
        getline(input, data);
        cau_hoi[i] = data;
        getline(input, data);
        dap_an[i][0] = data;
        getline(input, data);
        dap_an[i][1] = data;
        getline(input, data);
        dap_an[i][2] = data;
        getline(input, data);
        dap_an[i][3] = data;
        getline(input, data);
        dap_an_dung[i] = data[0];
        
    }
}
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
// Loại bỏ 2 đáp án sai
void NamMuoiNamMuoi(wchar_t dap_an_dung, int i)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3);
    wchar_t random_char = 'A' + dis(gen);
    if (random_char == dap_an_dung)
    {
        if (random_char == 'A' || random_char == 'B' || random_char == 'C')
            ++random_char;
        else
            --random_char;
    }
    if (dap_an_dung < random_char)
    {
        wcout << dap_an[i][dap_an_dung - 65] << endl;
        wcout << dap_an[i][random_char - 65] << endl;
    }
    else
    {
        wcout << dap_an[i][random_char - 65] << endl;
        wcout << dap_an[i][dap_an_dung - 65] << endl;
    }
}

void tro_giup(int t, int i)
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
        wcout << L"Xin mời bạn hỏi khán giả trong trường quay\n";
        wcout << L"Bạn có quyền hỏi 10 khán giả\n";
        int so_luong[5] = {0};
        for (int i = 1; i <= 10; i++)
        {
            wcout << "\n"
                  << L"Mời khán giả " << i << L" cho ý kiến: ";
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
        wcout << L"Đáp án A có : " << so_luong[1] << L" lựa chọn\n";
        wcout << L"Đáp án B có : " << so_luong[2] << L" lựa chọn\n";
        wcout << L"Đáp án C có : " << so_luong[3] << L" lựa chọn\n";
        wcout << L"Đáp án D có : " << so_luong[4] << L" lựa chọn\n";
        wcout << L"Lựa chọn cuối cùng của bạn là :";
    }
    else
    {
        NamMuoiNamMuoi(dap_an_dung[i], i);
    }
}
void in_sp(int &one, int &two, int &three)
{
    wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    wcout << L"Bạn còn các quyền trợ giúp là: \n";
    if (one != 0)
        wcout << L"  1. Năm mươi năm mươi\n";
    if (two != 0)
        wcout << L"  2. Gọi điện cho người thân\n";
    if (three != 0)
        wcout << L"  3. Hỏi ý kiến khán giả\n";
    wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void check_sp(int &one, int &two, int &three, int i)
{
    // Phần lưạ chọn đáp án hay trợ giúp ()
    wcout << L"Bạn có xử dụng quyền trợ giúp không (Có là 1 hoặc Không là 0): ";
    int yesno; wcin >> yesno;
    if (yesno == 1)
    {
        in_sp(one, two, three);
        wcout << L"Bạn sẽ sẽ dụng quyền trợ giúp nào : ";
        int t;
        wcin >> t;
        switch (t){
        case 1:
            one--;
            break;
        case 2:
            two--;
            break;
        case 3:
            three--;
            break;
        }
        tro_giup(t, i);
    }
}

// Phần trợ giúp Hỏi Ý Kiến Khán Giả
void HoiKhanGia()
{
    wcout << L"Nhập số khán giả hỏi";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        wcout << "\n"
              << L"Mời khán giả " << i << L" cho ý kiến: ";
        wstring s;
        wcin >> s;
    }
}

void in(wstring cau_hoi, wstring a, wstring b, wstring c, wstring d)
{
    // In câu hỏi và đáp án
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << "          " << cau_hoi << "\n";
    wcout << a << "          \t" << b << "\n";
    wcout << c << "          \t" << d << "\n";
}

void tro_choi(wstring cau_hoi, wstring a, wstring b, wstring c, wstring d, wchar_t result, int &flag)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Mời bạn chọn đáp án: ";
    wchar_t chon;
    wcin >> chon;
    if (toupper(chon) == toupper(result))
        wcout << L"Bạn trả lời đúng!!!\n";
    // flag = 1;
    else
    {
        wcout << L"Rất tiếc câu trả lời sai rồi !" << "\n";
        wcout << L"Đáp án của câu hỏi là: " << result << endl;
        flag = 0; // Nếu trả lời sai thì trò chơi dừng
    }
    wcout << "-----------------------------------------------------------------------------\n";
}