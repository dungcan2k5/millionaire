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
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    //locale loc(locale(), new codecvt_utf<wchar_t>);
    int dem = 0;
    draw_logo();
    int i = 0;
    while (i < 15)
    {
        int flag = 1;
        tro_choi(cau_hoi[i], dap_an[i][0], dap_an[i][1], dap_an[i][2], dap_an[i][3], dap_an_dung[i], flag);
        if (flag == 1)
            break;
        i++;
        dem++;
    }
    return 0;
}
