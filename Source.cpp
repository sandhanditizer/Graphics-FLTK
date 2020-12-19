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

    /*Graph_lib::Polygon p;
    p.add(Point{ 0, 0 });
    p.add(Point{ 1500, 0 });
    p.add(Point{ 1500, 150 });
    p.set_color(rand_color());
    p.set_fill_color(rand_color());
    win.attach(p);

    Graph_lib::Polygon p1;
    p1.add(Point{ 0, 0 });
    p1.add(Point{ 1500, 150 });
    p1.add(Point{ 0, 150 });
    p1.set_color(rand_color());
    p1.set_fill_color(Color::white);
    win.attach(p1);

    Graph_lib::Polygon p2;
    p2.add(Point{ 0, 150 });
    p2.add(Point{ 1500, 150 });
    p2.add(Point{ 1500, 300 });
    p2.set_color(rand_color());
    p2.set_fill_color(rand_color());
    win.attach(p2);

    Graph_lib::Polygon p3;
    p3.add(Point{ 0, 150 });
    p3.add(Point{ 0, 300 });
    p3.add(Point{ 1500, 300 });
    p3.set_color(rand_color());
    p3.set_fill_color(Color::white);
    win.attach(p3);

    Graph_lib::Polygon p4;
    p4.add(Point{ 0, 300 });
    p4.add(Point{ 1500, 300 });
    p4.add(Point{ 1500, 450 });
    p4.set_color(rand_color());
    p4.set_fill_color(rand_color());
    win.attach(p4);

    Graph_lib::Polygon p5;
    p5.add(Point{ 0, 300 });
    p5.add(Point{ 0, 450 });
    p5.add(Point{ 1500, 450 });
    p5.set_color(rand_color());
    p5.set_fill_color(Color::white);
    win.attach(p5);

    Graph_lib::Polygon p6;
    p6.add(Point{ 0, 450 });
    p6.add(Point{ 1500, 450 });
    p6.add(Point{ 1500, 600 });
    p6.set_color(rand_color());
    p6.set_fill_color(rand_color());
    win.attach(p6);

    Graph_lib::Polygon p7;
    p7.add(Point{ 0, 450 });
    p7.add(Point{ 0, 600 });
    p7.add(Point{ 1500, 600 });
    p7.set_color(rand_color());
    p7.set_fill_color(Color::white);
    win.attach(p7);

    Graph_lib::Polygon p8;
    p8.add(Point{ 0, 600 });
    p8.add(Point{ 1500, 600 });
    p8.add(Point{ 1500, 750 });
    p8.set_color(rand_color());
    p8.set_fill_color(rand_color());
    win.attach(p8);

    Graph_lib::Polygon p9;
    p9.add(Point{ 0, 600 });
    p9.add(Point{ 0, 750 });
    p9.add(Point{ 1500, 750 });
    p9.set_color(rand_color());
    p9.set_fill_color(Color::white);
    win.attach(p9);*/

    //----------------------------------- middle circles

    /*Graph_lib::Ellipse aa(Point{ 700, 115 }, 50, 10);
    aa.set_fill_color(Color::black);
    win.attach(aa);

    Circle a(Point{ 750, 75 }, 40);
    a.set_fill_color(rand_color());
    win.attach(a);*/

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

   /* Circle a4(Point{ 750, 375 }, 40);
    a4.set_fill_color(rand_color());
    win.attach(a4);

    Circle a2(Point{ 750, 525 }, 40);
    a2.set_fill_color(rand_color());
    win.attach(a2);

    Circle a3(Point{ 750, 675 }, 40);
    a3.set_fill_color(rand_color());
    win.attach(a3);*/

    //-------------------------------- right circles

   /* Circle b(Point{ 375, 0 }, 40);
    b.set_fill_color(rand_color());
    win.attach(b);

    Circle b1(Point{ 375, 150 }, 40);
    b1.set_fill_color(rand_color());
    win.attach(b1);

    Circle b2(Point{ 375, 300 }, 40);
    b2.set_fill_color(rand_color());
    win.attach(b2);

    Circle b3(Point{ 375, 450 }, 40);
    b3.set_fill_color(rand_color());
    win.attach(b3);

    Circle b4(Point{ 375, 600 }, 40);
    b4.set_fill_color(rand_color());
    win.attach(b4);

    Circle b5(Point{ 375, 750 }, 40);
    b5.set_fill_color(rand_color());
    win.attach(b5);*/

    //-------------------------------

    win.wait_for_button();
}

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

