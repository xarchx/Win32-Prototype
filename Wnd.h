#pragma once

#include <Windows.h>
#include <string>
#include <assert.h>
#include <queue>

struct WndCreateInfo
{
	LPCSTR lpName;
	LPCSTR lpClass;
	HWND lpParent;
	int x;
	int y;
	int cx;
	int cy;
	DWORD style;
	DWORD styleEx;
};


class Wnd
{
public:
	Wnd(Wnd* parent);
	Wnd(Wnd* parent, int x, int y, int w, int h, const TCHAR* text);
	
	bool Create();
	void Show();
	static LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

	Wnd* m_parent;
	std::string m_text;
	HWND m_hwnd;
	std::string lpClass;
	std::string lpText;
	DWORD style;
	struct 
	{
		int x, y, cx, cy;
	}geo;
	//WndCreateInfo& info;
};

