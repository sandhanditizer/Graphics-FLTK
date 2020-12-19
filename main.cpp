/*
Zachariah Kline
30 Nov 2020
Creating an abstract like image that can be easily manipulated by small inputs
LINK OF INSPIRATION: https://thumbs.dreamstime.com/z/set-geometric-shapes-vector-illustration-flower-life-sacred-geometry-ancient-symbol-67510102.jpg\
andddddddd because december is a "space watch" month
*/

#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include <cmath>

double radians(double angle);
void flower(vector<Point>& v, double length);

int main() {
    Simple_window win{ Point{0,0}, 2000, 1000, "Star Heart" };

    Graph_lib::Image stars(Point{ 0,0 }, "Stars.jpg");  //Star background
    Graph_lib::Image stars1(Point{ 300,0 }, "Stars.jpg");
    Graph_lib::Image stars2(Point{ 600,0 }, "Stars.jpg");
    Graph_lib::Image stars3(Point{ 900,0 }, "Stars.jpg");
    Graph_lib::Image stars4(Point{ 0,500 }, "Stars.jpg");
    Graph_lib::Image stars5(Point{ 300,500 }, "Stars.jpg");
    Graph_lib::Image stars6(Point{ 600,500 }, "Stars.jpg");
    Graph_lib::Image stars7(Point{ 900,500 }, "Stars.jpg");

    //-------------------------------------------------------------------------

    Graph_lib::Open_polyline star_left;
    vector<Point> points;
    flower(points, 84);
    star_left.set_color(14);
    for (Point p : points) {
        p.x += 81;  //This is how you move the star
        p.y += 500;
        star_left.add(p);
    }

    Circle s(Point{ 81, 500 }, 84);  //Background color for star_left
    s.set_color(Color::cyan);
    s.set_fill_color(Color::cyan);

    Graph_lib::Open_polyline star_mid;
    vector<Point> points2;
    flower(points2, 310);
    star_mid.set_color(Color::yellow);
    for (Point& p : points2) {
        p.x += 800;
        p.y += 500;
        star_mid.add(p);
    }

    Circle s1(Point{ 800, 500 }, 310);  //Background color for star_mid
    s1.set_color(Color::dark_red);
    s1.set_fill_color(Color::dark_red);

    Graph_lib::Open_polyline star_right;
    vector<Point> points3;
    flower(points3, 700);
    star_right.set_color(Color::red);
    for (Point& p : points3) {
        p.x += 2000; //moved over to the right side of the screen
        p.y += 500;
        star_right.add(p);
    }

    Circle s2(Point{ 2000, 500 }, 700);  //Background color for star_right
    s2.set_color(Color::dark_yellow);
    s2.set_fill_color(Color::dark_yellow);

    //-------------------------------------------------------------------------

    Graph_lib::Open_polyline a;  //Ceiling
    a.add(Point{ 1230,0 });
    a.add(Point{ 20,425 });
    a.add(Point{ 70, 425 });
    a.add(Point{ 1420, 0 });
    a.set_color(Color::magenta);
    a.set_fill_color(0);

    Graph_lib::Open_polyline b;  //Floor
    b.add(Point{ 1230,1000 });
    b.add(Point{ 20,575 });
    b.add(Point{ 70, 575 });
    b.add(Point{ 1420, 1000 });
    b.set_color(Color::magenta);
    b.set_fill_color(0);

    Graph_lib::Open_polyline c;  // c-e is the white rope
    c.add(Point{ 870,500 });
    c.add(Point{ 1850,500 });
    c.set_color(Color::white);

    Graph_lib::Open_polyline d;
    d.add(Point{ 870,501 });
    d.add(Point{ 1850,501 });
    d.set_color(Color::white);

    Graph_lib::Open_polyline e;
    e.add(Point{ 730,500 });
    e.add(Point{ 90,500 });
    e.set_color(Color::white);

    Graph_lib::Open_polyline f;  //f and g is extra detail
    f.add(Point{ 20,0 });
    f.add(Point{ 20,425 });
    f.add(Point{ 1230,0 });
    f.add(Point{ 20,0 });
    f.set_color(Color::magenta);
    f.set_fill_color(Color::black);

    Graph_lib::Open_polyline g;
    g.add(Point{ 1230,1000 });
    g.add(Point{ 20,575 });
    g.add(Point{ 20,1000 });
    g.add(Point{ 1230,1000 });
    g.set_color(Color::magenta);
    g.set_fill_color(Color::black);

    //-------------------------------------------------------------------------

    win.attach(stars);
    win.attach(stars1);
    win.attach(stars2);
    win.attach(stars3);
    win.attach(stars4);
    win.attach(stars5);
    win.attach(stars6);
    win.attach(stars7);

    win.attach(a);
    win.attach(b);
    win.attach(s);
    win.attach(star_left);
    win.attach(e);
    win.attach(s1);
    win.attach(star_mid);
    win.attach(c);
    win.attach(d);
    win.attach(s2);
    win.attach(star_right);
    win.attach(f);
    win.attach(g);

    win.wait_for_button();
}

//-------------------------------------------------------------------------

//degrees conversion
double radians(double angle) {
    double radian = angle * 3.14159;
    radian /= 180;
    return radian;
}
//creates a swurl of lines (the star)
void flower(vector<Point>& v, double length) {
    Point start{};
    double angle = radians(180); //enter in degrees get radians

    for (int i = 0; i < 800; ++i) {
        start.x = round(length * cos(angle));
        start.y = round(length * -sin(angle));
        angle *= 2; //1.5(cardioid), 2(cardioid), 4(clover)
        v.push_back(start);
    }
}
