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
        WINHTTP_NO_PROXY_BYPASS, 
        
        0
    );

    wchar_t* uri =/*  L"example.com"; *//*  L"fias.nalog.ru"; */ /* L"fias-public-service.nalog.ru"; */ L"nspd.gov.ru";
    // "https://fias-public-service.nalog.ru/api/spas/v2.0/GetAddressItemById?object_id=163731632&address_type=2"


    // "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1"
    // "https://fias-public-service.nalog.ru/api/spas/v2.0/GetAddressItemById?object_id=3222701976&address_type=2"


    HINTERNET hConnect = WinHttpConnect(
        hSession,
        uri,
        INTERNET_DEFAULT_HTTP_PORT,
        0
    );

    HINTERNET hRequest = WinHttpOpenRequest(
        hConnect,
        L"GET", 
        L"/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1",
        NULL, 
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES, 
        0
    );


    
    // DWORD dwFlags = SECURITY_FLAG_IGNORE_UNKNOWN_CA |
    //                 SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
    //                 SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

    // WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &dwFlags, sizeof(dwFlags));


    BOOL bResults = WinHttpSendRequest(
        hRequest,
        /* headders, */ WINHTTP_NO_ADDITIONAL_HEADERS,
        0,
        WINHTTP_NO_REQUEST_DATA, 
        0,
        0, 
        0
    );

    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);

    system("chcp 65001 > nul");

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

            std::string response;
            do {
                // Узнаём, сколько байт доступно
                if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) break;
                if (dwSize == 0) break;

                size_t start = response.size();
                response.resize(start + dwSize); // резервируем память

                // читаем данные прямо в конец строки
                if (!WinHttpReadData(hRequest, response.data() + start, dwSize, &dwDownloaded)) break;

                // обрезаем строку до фактического числа байт
                response.resize(start + dwDownloaded);
                std::cout << response;
            } while (dwSize > 0);

        } while (dwSize > 0);
    } else {
        std::wcerr << L"Request failed, error: " << GetLastError() << std::endl;
    }


    // Очистка
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);

    return 0;
}   





// std::string HTTPGet (const std::wstring& url) {
//      HINTERNET hSession = WinHttpOpen(
//         L"WinHTTP Example/1.0", 
//         WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, 
//         WINHTTP_NO_PROXY_NAME, 
//         WINHTTP_NO_PROXY_BYPASS, 0
//     );

//     wchar_t* uri = L"nspd.gov.ru";


//     HINTERNET hConnect = WinHttpConnect(
//         hSession,
//         uri,
//         INTERNET_DEFAULT_HTTP_PORT,
//         0
//     );

//     HINTERNET hRequest = WinHttpOpenRequest(
//         hConnect,
//         L"GET", 
//         L"/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1",
//         NULL, 
//         WINHTTP_NO_REFERER,
//         WINHTTP_DEFAULT_ACCEPT_TYPES, 
//         0
//     );

//     // DWORD dwFlags = SECURITY_FLAG_IGNORE_UNKNOWN_CA |
//     //                 SECURITY_FLAG_IGNORE_CERT_CN_INVALID |
//     //                 SECURITY_FLAG_IGNORE_CERT_DATE_INVALID;

//     // WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &dwFlags, sizeof(dwFlags));

//     BOOL bResults = WinHttpSendRequest(
//         hRequest,
//         WINHTTP_NO_ADDITIONAL_HEADERS,
//         0,
//         WINHTTP_NO_REQUEST_DATA, 
//         0,
//         0, 
//         0
//     );

//     if (bResults)
//         bResults = WinHttpReceiveResponse(hRequest, NULL);

//     system("chcp 65001 > nul");

//     std::string fullResponse;
//     if (bResults) {
//         DWORD dwSize = 0;
//         do {
//             DWORD dwDownloaded = 0;
//             if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
//                 std::wcerr << L"QueryDataAvailable failed: " << GetLastError() << std::endl;
//                 break;
//             }

//             if (dwSize == 0)
//                 break;

//             std::string response;
//             do {
//                 // Узнаём, сколько байт доступно
//                 if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) break;
//                 if (dwSize == 0) break;

//                 size_t start = response.size();
//                 response.resize(start + dwSize); // резервируем память

//                 // читаем данные прямо в конец строки
//                 if (!WinHttpReadData(hRequest, response.data() + start, dwSize, &dwDownloaded)) break;

//                 // обрезаем строку до фактического числа байт
//                 response.resize(start + dwDownloaded);
//                 std::cout << response;
//             } while (dwSize > 0);

//         } while (dwSize > 0);
//     } else {
//         std::wcerr << L"Request failed, error: " << GetLastError() << std::endl;
//     }

//     // Очистка
//     if (hRequest) WinHttpCloseHandle(hRequest);
//     if (hConnect) WinHttpCloseHandle(hConnect);
//     if (hSession) WinHttpCloseHandle(hSession);

//     return 0;
// }