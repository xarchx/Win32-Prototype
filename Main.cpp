#include <Wnd.h>

struct App
{
	int exe() {
		MSG msg{};
		while (GetMessage(&msg, NULL, NULL, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.lParam;
	}
};


int main(int args, char* argv[])
{
	App app;

	Wnd window(nullptr, 700, 200, 700, 400,"main window");
	window.Create();
	window.Show();

	Wnd button(&window, 50, 50, 300, 100, "Button1");
	button.lpClass = "Button";
	button.Create();

	return app.exe();
}