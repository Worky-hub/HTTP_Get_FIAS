#include <iostream>
#include <windows.h>
#include <winhttp.h>
#include <string>

#include <newtwork/uri.hpp>

// #define BOOST_URL_HEADER_ONLY
// #include <boost/url.hpp>

// #pragma comment(lib, "winhttp.lib")
// namespace urls = boost::urls;
// namespace urls = boost::urls;

int main() {


    // const std::string& url = "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    // wchar_t url[] = L"https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    std::string url = "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    network::uri theUrl (url);
    // auto parsedUrl = urls::parse_uri(url);
    // urls::url_view u = *parsedUrl;
    // std::cout << u.scheme();


    // std::wstring wurl(url.begin(), url.end());


    std::cout << "Scheme: " << theUrl.scheme();



    // std::string lol = WinHttpCrackUrl();


    return 0;
}