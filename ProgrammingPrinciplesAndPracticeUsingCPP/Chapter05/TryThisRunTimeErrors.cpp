#include <iostream>

constexpr int frame_width { 2 };

// calculate area of a rectangle;
// return -1 to indicate a bad argument
int area (int length, int width)
{
    if (length <= 0 || width <= 0) return -1;
    return length * width;
}

// calculate area within frame
int framed_area (int x, int y)
{
    return area (x - frame_width, y - frame_width);
}

// Example function
int f (int x, int y, int z)
{
    int area1 = area (x, y);
    if (area1 <= 0) error ("non-positive area");

    // area2, with frame_width of 2 will always be erroneous
    // It is nonsense to preserve it then
    //int area2 = framed_area(1, z);

    int area3 = framed_area (y, z);
    if (area3 <= 0) error ("non-positive area");

    // by getting here, having pass through the previous test to area3,
    // we can be sure ratio would not cause division by zero
    double ratio = double (area1) / area3;

    cout << "\tarea1, area(x,y): " << area1 << '\n'
        //<< "\tarea2, framed_area(1, z): " << area2 << '\n'
        << "\tarea3, framed_area(y, z): " << area3 << '\n'
        << "\tratio, area1/area3: " << ratio << '\n';

    return 0;
}

int main ()
{
    int x { 0 };
    int y { 0 };
    int z { 0 };

    while (cin >> x >> y >> z) {
        cout << "x:" << x << ", y:" << y << ", z:" << z << '\n';
        f (x, y, z);
    }

    return 0;
}