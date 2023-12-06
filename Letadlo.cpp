#include "Letadlo.h"
#include <cmath>

Letadlo::Letadlo(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool Letadlo::find() {
    Point current = start;

    while (current != finish) {
        path.push_back(current);

        Point next = current;
        if (current.x < finish.x) next.x+=sqrt(2);
        else if (current.x > finish.x) next.x-=sqrt(2);

        if (current.y < finish.y) next.y+=sqrt(2);
        else if (current.y > finish.y) next.y-=sqrt(2);

        current = next;
    }

    path.push_back(finish);
    return true;
}
