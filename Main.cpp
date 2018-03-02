# include <Siv3D.hpp>
#include "ProgressiveLine.hpp"

void Main()
{
    Vec2 start(100,100);
    Vec2 end(300,300);
    Font font(16);
    bool gs = false,ge = false;
    float t = 0;
    double et = 0;
    
    while (System::Update())
    {
        ProgressiveLine pl(start,end);
        Circle sc(start,6);
        Circle ec(end,6);
        ClearPrint();
        
        t += Mouse::Wheel() / 50;
        if(KeyRight.pressed()) t += 0.01;
        if(KeyLeft.pressed()) t -= 0.01;
        if(t > 1) t = 1;
        if(t < 0) t = 0;
        
        if(sc.leftClicked())
            gs = true;
        else if(MouseL.up()) gs = false;
        else if(gs) start.set(Cursor::Pos());
        
        if(ec.leftClicked())
            ge = true;
        else if(MouseL.up()) ge = false;
        else if(ge) end.set(Cursor::Pos());
        
        pl.line(EaseOut(Easing::Quad, t)).draw(Palette::Yellow);
        sc.draw(Palette::Green);
        ec.draw(Palette::Green);
        
        font(U"t=", t).draw(Vec2(pl.line(EaseOut(Easing::Quad, t)).end.x, pl.line(EaseOut(Easing::Quad, t)).end.y - 16));
        font(start).draw(Vec2(start.x, start.y - 8));
        font(end).draw(end);
    }
}
