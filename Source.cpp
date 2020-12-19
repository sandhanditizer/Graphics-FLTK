#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <random>
#include <vector>


int rand_int(int min, int max);
Point rand_location(int width, int height);
int rand_color();

int main() {
    using namespace Graph_lib;
    int max{100};
    int min{0};

    Point t1{ 0, 0 };
    Simple_window win{ t1, 1500, 750, "Cool Drawy Thing" };

    Graph_lib::Polygon bg;
    bg.add(Point{ 0,0 });
    bg.add(Point{ 1500,0 });
    bg.add(Point{ 1500,750 });
    bg.add(Point{ 0,750 });
    bg.set_fill_color(Color::dark_green);
    win.attach(bg);

    Graph_lib::Rectangle sky(Point{ 0,0 }, 1500, 200);
    sky.set_fill_color(Color::blue);
    sky.set_color(Color::blue);
    win.attach(sky);

    Graph_lib::Polygon shadow;
    shadow.add(Point{ 620,200 });
    shadow.add(Point{ 640,200 });
    shadow.add(Point{ 712,275 });
    shadow.add(Point{ 692,275 });
    shadow.set_fill_color(404040);
    shadow.set_color(404040);
    win.attach(shadow);

    Graph_lib::Ellipse hole(Point{ 700, 260 }, 70, 15);
    hole.set_fill_color(Color::black);
    hole.set_color(Color::black);
    win.attach(hole);

    Graph_lib::Rectangle shadow2(Point{ 665, 246 }, 18, 27);
    shadow2.set_fill_color(404040);
    shadow2.set_color(404040);
    win.attach(shadow2);

    Graph_lib::Rectangle flag(Point{ 692,0 }, 20, 275);
    flag.set_fill_color(Color::red);
    flag.set_color(Color::dark_magenta);
    win.attach(flag);

    Circle ball(Point{ 750, 225 }, 40);
    ball.set_fill_color(Color::white);
    win.attach(ball);

    win.wait_for_button();
}
// For if I evever wanted to use these for making random things
int rand_int(int min, int max) {
    static std::random_device rd;
    static std::default_random_engine engine{ rd() };
    std::uniform_int_distribution<int> dist{ min, max };
    return dist(engine);
}

Point rand_location(int width, int height) {
    int x = rand_int(0, width - 20);
    int y = rand_int(0, height - 20);
    return Point{ x, y };
}

int rand_color() {
    int x = rand_int(0, 13);
    return x;
}

