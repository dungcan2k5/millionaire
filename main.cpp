#include "welcome.h"

#include <windows.h>
#include <conio.h>

int main()
{
    SetConsoleTitleW(L"GameShow: Ai Là Triệu Phú");
    system("mode 140, 35");

    welcomeScreen();
    choiceMode();
}