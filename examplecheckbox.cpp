#include "examplecheckbox.hpp"
#include "graphics.hpp"
using namespace genv;

CheckBox::CheckBox(Window* w,int x, int y, int sx, int sy)
    : formWidget(w,x,y,sx,sy)
{
    _checked=false;
}

void CheckBox::draw() const
{
     canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 15);

    c<<color(255,255,255);
    c << move_to(0, 0) << color(255,255,255) << box(_sx, _sy);
    c << move_to(2, 2) << color(0,0,0) << box(_sx-4, _sy-4);
    if (_checked) {
        c << color(255,255,255);
        c << move_to(4, 4) << line(_sx-8, _sy-8);
        c << move_to(5, 4) << line(_sx-8, _sy-8);
        c << move_to(_sx-4, 4) << line(-_sx+8, _sy-8);
        c << move_to(_sx-5, 4) << line(-_sx+8, _sy-8);
    }
    gout << stamp(c, _px, _py);
}

void CheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
        _checked = !_checked;
    }
    if (ev.type == ev_mouse && isActive && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool CheckBox::is_checked() const
{
    return _checked;
}
