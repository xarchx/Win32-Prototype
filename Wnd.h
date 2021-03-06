#pragma once


class Wnd
{
public:
	Wnd(Wnd* parent);
	Wnd(Wnd* parent, int x, int y, int w, int h, const TCHAR* text);
	virtual ~Wnd();
	
	virtual bool Create();
	void Show();
	const char* GetText() const;
	virtual LRESULT DrawItemEvent(DRAWITEMSTRUCT* dis);
	virtual LRESULT LocalWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static LRESULT WINAPI GlobalWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

	Wnd* m_parent;
	HWND m_hwnd;
	std::string lpClass;
	std::string lpText;
	DWORD style;
	struct {
		int x, y, cx, cy;
	}geo;
	bool is_control = false;
};

