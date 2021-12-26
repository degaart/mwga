#include "window_styles.h"
#include <Windows.h>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

#define APP_NAME L"MWGA"
#define HERE() do { std::cout << "[" << __LINE__ << "]\n"; } while(false)

HINSTANCE hinst;

template<typename T, typename Function>
inline void iterate_str(const std::basic_string<T>& s, const std::basic_regex<T>& r, Function fn)
{
    std::regex_token_iterator<typename std::basic_string<T>::const_iterator> it(s.begin(), s.end(), r, -1);
    std::regex_token_iterator<typename std::basic_string<T>::const_iterator> end;
    for(; it != end; ++it) {
        fn(it->str());
    }
}

template<typename T>
inline std::vector<std::basic_string<T>> split_str(const std::basic_string<T>& s, const std::basic_regex<T>& r)
{
    std::vector<std::basic_string<T>> result;
    iterate_str(s, r, [&result](const std::basic_string<T>& s) {
        result.push_back(s);
    });
    return result;
}

unsigned parseStyle(const std::wstring& s)
{
    static const std::wregex r(L"\\s*\\|\\s*");
    unsigned result = 0;
    auto tokens = split_str(s, r);
    for(const auto& token : tokens) {
        if(!token.empty()) {
            auto it = _stylesMap.find(token);
            if(it == _stylesMap.end()) {
                std::wcerr << L"Invalid style: " << token << L"\n";
                throw std::runtime_error("Invalid style");
            }
            result |= it->second;
        }
    }
    return result;
}

struct Control {
    std::wstring className;
    std::wstring caption;
    unsigned style;
    int x, y, w, h;
    intptr_t id;
    HWND hwnd;
};
std::vector<Control> _controls;

std::vector<Control> loadControls(const std::wstring& filename)
{
    using namespace std;
    vector<Control> controls;

    wifstream is(L"controls.csv", ios::in);
    if(!is)
        throw system_error(errno, system_category());
    is.exceptions(ios::badbit);
    is.imbue(locale(is.getloc(), new codecvt_utf16<wchar_t, 0x10ffff, consume_header>));
    
    wregex tokenSep(L"\\s*;\\s*");

    wstring line;
    int line_number = 1;
    while(getline(is, line)) {
        vector<wstring> tokens = split_str(line, tokenSep);
        if(tokens.size() == 8) {
            Control ctl;
            ctl.className = tokens[0];
            ctl.caption = tokens[1];
            ctl.style = parseStyle(tokens[2]);
            ctl.x = stoi(tokens[3]);
            ctl.y = stoi(tokens[4]);
            ctl.w = stoi(tokens[5]);
            ctl.h = stoi(tokens[6]);
            ctl.id = stoi(tokens[7]);
            controls.push_back(std::move(ctl));
        } else if(tokens.size() > 1) {
            stringstream ss;
            ss << "Error at line " << line_number << ", found " << tokens.size() << " tokens\n";
            throw std::runtime_error(ss.str());
        }
        line_number++;
    }
    return controls;
}

void createControls(HWND hwnd, std::vector<Control>& controls)
{
    for(auto& ctl : controls) {
        auto hctl = CreateWindow(
                ctl.className.c_str(),
                ctl.caption.c_str(),
                ctl.style,
                ctl.x, ctl.y, ctl.w, ctl.h,
                hwnd,
                reinterpret_cast<HMENU>(ctl.id),
                hinst,
                nullptr);
        if(!hctl) {
            throw std::runtime_error("Failed to create control");
        }
        ctl.hwnd = hctl;
    }
}

void refreshWindow(HWND hwnd, const std::wstring& filename)
{
    for(auto& ctl : _controls) {
        DestroyWindow(ctl.hwnd);
    }
    _controls = loadControls(filename);
    createControls(hwnd, _controls);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg) {
        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_KEYUP:
            if(wparam == VK_F5) {
                refreshWindow(hwnd, L"controls.csv");
            }
            return 0;
    }
}

INT APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    hinst = hInstance;

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = APP_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
            APP_NAME,
            APP_NAME,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            CW_USEDEFAULT, CW_USEDEFAULT,
            NULL,
            NULL,
            hInstance,
            NULL);
    if(!hwnd)
        return -1;

    _controls = loadControls(L"controls.csv");
    createControls(hwnd, _controls);

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}




