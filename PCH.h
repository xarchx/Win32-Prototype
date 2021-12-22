#pragma once

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "comctl32.lib")

#include <CommCtrl.h>

#include <string>
#include <assert.h>
#include <queue>
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define LOG(x, ...)	Log::log_format(x, ##__VA_ARGS__)

typedef TCHAR tchar;

namespace Log
{
	template<typename ... Args>
	void log_format(const char* code, Args ...args) {
		size_t len = snprintf(nullptr, 0, code, args ...) + 1;
		TCHAR* buf = new TCHAR[len];
		snprintf(buf, len, code, args ...);
		std::cout << buf << std::endl;
		delete buf;
	}
}