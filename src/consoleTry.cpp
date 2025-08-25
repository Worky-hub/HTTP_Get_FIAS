#include <windows.h> 
#include <iostream>
#include <fcntl.h> 
#include <io.h>
#include <clocale>
#include <string>
#include <cstdlib>

int main () {
// chcp 65001;
// chcp 866;
    // system("chcp 65001 > nul");
    // SetConsoleOutputCP(1251);
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);

    // std::setlocale(LC_ALL, "ru_RU.UTF-8");
    // std::setlocale(LC_ALL, "ru_Ru");

    // std::string current_locale = setlocale(LC_ALL, NULL);


    // SetConsoleOutputCP

    // SetConsoleCP(CP_UTF8);



    // _setmode(_fileno(stdout), _O_U8TEXT);


    // char16_t symb = L"sdfg"[2];
// char symb = L"sdfg"[2];

    std::wstring utf16text = L"Bom Привет мир! 🌍";
    // wchar_t wch = L'Ппва';
    std::wcout << utf16text;
    // MessageBoxW(0, utf16text, L"Hello", 0);

    // Получаем дескриптор стандартного вывода
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // Пишем в консоль напрямую через WinAPI
    // DWORD written;
    // WriteConsoleW(hConsole, utf16text.c_str(), utf16text.length(), &written, nullptr);

    return 0;


    // SetConsoleOutputCP(CP_UTF8);

    // _setmode(_fileno(stdout), _O_U8TEXT);



    // std::wstring wResponse = Utf8ToUtf16(responseStr); 
    // std::wcout << wResponse << std::endl;

}






