#include <iostream>
#include <winsock2.h> //winsock2.h have to be included before windows.h, cuz otherwise boost asio (which is inside boost) include, and use winsock1.h automatically.
#include <windows.h>
#include <winhttp.h>
#include <string>

// #include <boost/url.hpp>

#include <C:\cppWorkspace\Projects\Work_Projects\FIAS\Get_Requests\vcpkg_installed\x64-windows\include\boost/network/uri/uri.hpp>


#include <C:\cppWorkspace\Projects\Work_Projects\FIAS\Get_Requests\vcpkg_installed\x64-windows\include\boost/network/protocol/http/client.hpp>





// #define BOOST_URL_HEADER_ONLY
// #include <boost/url.hpp>

// #pragma comment(lib, "winhttp.lib")
// namespace urls = boost::urls;
// namespace urls = boost::urls;
namespace http = boost::network::http;
int main() {
    using namespace boost::network;
    // const std::string& url = "https://nspd.gov.ru/api/geoporctal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    // wchar_t url[] = L"https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";
    std::string url = "https://nspd.gov.ru/api/geoportal/v2/search/geoportal?query=77%3A21%3A0151004%3A11&thematicSearchId=1";

    boost::network::uri::uri url(url);
    // uri (url);
    // auto parsedUrl = urls::parse_uri(url);
    // urls::url_view u = *parsedUrl;
    // std::cout << u.scheme();


    // std::wstring wurl(url.begin(), url.end());


    // std::cout << "url: " << url << std::endl;
    // std::cout << "Scheme: " << url.scheme();


    // std::string lol = WinHttpCrackUrl();


    return 0;
}