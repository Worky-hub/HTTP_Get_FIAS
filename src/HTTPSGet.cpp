#include <iostream>
#include <windows.h>
// #include <sstream>
#include <string>
#include <winhttp.h>
#include <io.h>
#include <fcntl.h> 

#pragma comment(lib, "User32.lib")

int main () {


    HINTERNET hSession = WinHttpOpen(
        L"WinHTTP Example/1.0", 
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, 
        WINHTTP_NO_PROXY_NAME, 
        WINHTTP_NO_PROXY_BYPASS, 0
    );

    wchar_t* uri =/*  L"example.com"; *//*  L"fias.nalog.ru"; */ /* L"fias-public-service.nalog.ru"; */ L"nspd.gov.ru";
// "https://fias-public-service.nalog.ru/api/spas/v2.0/GetAddressItemById?object_id=163731632&address_type=2"


// "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1"
// "https://fias-public-service.nalog.ru/api/spas/v2.0/GetAddressItemById?object_id=3222701976&address_type=2"


    HINTERNET hConnect = WinHttpConnect(
        hSession,
        uri,
        INTERNET_DEFAULT_HTTPS_PORT,
        0
    );

    HINTERNET hRequest = WinHttpOpenRequest(
        hConnect,
        // NULL,
        // NULL,
        L"GET", 
        // L"/api/spas/v2.0/GetAddressItemById?object_id=163731632&address_type=2",
        L"/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1",
        NULL, 
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE
    );


    
DWORD dwFlags = SECURITY_FLAG_IGNORE_UNKNOWN_CA |
                SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
                SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &dwFlags, sizeof(dwFlags));



    // LPCWSTR headders = L"Accept: application/json, text/javascript, */*; q=0.01\r\nconnection: keep-alive\r\nMaster-token: bfa2407b-1dc4-4714-9346-b678408eb099\r\nUser-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36";
    
    BOOL bResults = WinHttpSendRequest(
        hRequest,
        /* headders, */ WINHTTP_NO_ADDITIONAL_HEADERS,
        0,
        WINHTTP_NO_REQUEST_DATA, 
        0,
        0, 
        0
    );


    // std::string responseHtml = bResults;

    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);


    // _setmode(_fileno(stdout), _O_U8TEXT);
    // std::setlocale(LC_ALL, "ru_RU.UTF-8");

    // std::string responseHtml;
    // std::setlocale(LC_ALL, "ru_Ru");

    system("chcp 65001 > nul");
    // SetConsoleOutputCP(1251);
    // SetConsoleCP(1251);
    // SetConsoleCP(CP_UTF8);
    std::string fullResponse;
    if (bResults) {
        DWORD dwSize = 0;
        do {
            DWORD dwDownloaded = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                std::wcerr << L"QueryDataAvailable failed: " << GetLastError() << std::endl;
                break;
            }

            if (dwSize == 0)
                break;

            char* buffer = new char[dwSize + 1];
            ZeroMemory(buffer, dwSize + 1);

            if (WinHttpReadData(hRequest, buffer, dwSize, &dwDownloaded))
                fullResponse.append(buffer, dwDownloaded);
                // MessageBoxW(0, fullResponse, L"lol", 0);
                std::string result(buffer);
                std::cout << result;
                delete[] buffer;
            // responseHtml = std::string(buffer, dwDownloaded);

        } while (dwSize > 0);
    } else {
        std::wcerr << L"Request failed, error: " << GetLastError() << std::endl;
    }



    // Очистка
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

    
    // MessageBoxW(0, responseHtml.c_str(), L"Nu Cheee", 0);
    

    // delete[] buffer;

    return 0;
    // std::cout << "Press Enter to exit...";
    // std::cin.get();
}   
