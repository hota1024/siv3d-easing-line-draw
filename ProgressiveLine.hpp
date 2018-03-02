#ifndef ProgressiveLine_hpp
#define ProgressiveLine_hpp

#include <Siv3D.hpp>

class ProgressiveLine{
public:
    Vec2 start;
    Vec2 end;
    
    ProgressiveLine(): start(0,0),end(0,0){}
    ProgressiveLine(Vec2 start, Vec2 end): start(start),end(end){}
    
    Line line(float progress){
        return Line(start,{start.x + (end.x - start.x) * progress,start.y + (end.y - start.y) * progress});
    }
};

#endif
