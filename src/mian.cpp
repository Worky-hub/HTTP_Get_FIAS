#include <iostream>
#include <windows.h>
#include <winhttp.h>
#include <string>

#pragma comment(lib, "winhttp.lib")
int::main() {
    // const std::string& url = "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    // wchar_t url[] = L"https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    std::string url = "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";

 
    std::wstring wurl(url.begin(), url.end());






    // std::string lol = WinHttpCrackUrl();

    



    return 0;
}