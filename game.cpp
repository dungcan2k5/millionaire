#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <locale>
#include <codecvt>
#include "mylst.h"
using namespace std;
int one = 1, two = 1, three = 1;
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    // locale loc(locale(), new codecvt_utf<wchar_t>);
    int dem = 0;// đếm số câu trả lời đúng
    draw_logo();
    int i = 0;
    int count_sp = 3; // Biến đếm số lương trợ giúp
    //int flag = 1;
    while (i < 15){
        int flag = 1;
        in(cau_hoi[i], dap_an[i][0], dap_an[i][1], dap_an[i][2], dap_an[i][3]);
        //in_sp(one, two, three);
        check_sp(one, two, three, i);
        tro_choi(cau_hoi[i], dap_an[i][0], dap_an[i][1], dap_an[i][2], dap_an[i][3], dap_an_dung[i], flag);
        if (flag == 0){
            //wcout << L"Bạn đã trả lời đúng " << dem << L" câu." << endl;
            break;
        }else{
            dem++;
        }
        i++;
    }
    wcout << L"Bạn đã trả lời đúng " << dem << L" câu." << endl;
    return 0;
}
