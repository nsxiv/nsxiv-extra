extern win_t win;
extern img_t img;
bool cg_toggle_winbg(arg_t _)
{
	win.win_bg.pixel ^= ~0;
	win.win_bg.red   ^= ~0;
	win.win_bg.green ^= ~0;
	win.win_bg.blue  ^= ~0;
	img.dirty = true;
	return true;
}
#define g_toggle_winbg { cg_toggle_winbg, MODE_ALL }
