#include "Wnd.h"

Wnd::Wnd(Wnd* parent)
	: m_parent(parent), geo{0},lpClass("Wnd32"), lpText("Wnd32"), style(WS_VISIBLE)
{
	
}

Wnd::Wnd(Wnd* parent, int x, int y, int w, int h, const TCHAR* text)
	: m_parent(parent), geo{ x, y, w, h}, lpClass("Wnd32"), lpText(text), style(WS_VISIBLE)
{

}

LRESULT Wnd::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	return DefWindowProc(hwnd, msg, wp, lp);
}

bool Wnd::Create()
{
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = lpClass.c_str();
	wc.lpfnWndProc = Wnd::WndProc;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	if (!GetClassInfoEx(wc.hInstance, wc.lpszClassName, &wc)) {
		if (!RegisterClassEx(&wc)) {
			assert(0);
		}
	}

	HWND parent_hwnd = nullptr;
	if (m_parent) {
		if (m_parent->m_hwnd)
			parent_hwnd = m_parent->m_hwnd;
	}

	if (parent_hwnd) {
		style &= ~WS_POPUP; style |= WS_CHILD;
	}else {
		style &= ~WS_CHILD; style |= WS_POPUP;
	}

	m_hwnd = CreateWindowEx(
		NULL,
		lpClass.c_str(),
		lpText.c_str(),
		style,
		geo.x, geo.y, geo.cx, geo.cy,
		parent_hwnd, (HMENU)NULL, wc.hInstance, this);

	if (!m_hwnd) {
		return false;
	}
		

	return true;
}

void Wnd::Show()
{
	ShowWindow(m_hwnd, TRUE);
}
