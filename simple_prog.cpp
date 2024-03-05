#include <iostream>
#include <forward_list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Point
{
protected:
    double _x;
    double _y;
    double _z;

public:
    Point(double x, double y, double z): _x(x), _y(y), _z(z) {}
    
    double x() const 
    {
        return _x;
    }
    double y() const 
    {
        return _y;
    }
    double z() const 
    {
        return _z;
    }
};

class Scene 
{
protected:
    vector<Point> points;

public:
    virtual bool contains(const Point& p) const // виртуальный метод, который проверяет, содержит ли сцена определенную точку
    {
        return true; // базовая реализация принимает все точки
    }

    void append(const Point& p) // обавляет точку на сцену, если она проходит проверку метода contains()
    {
        if (contains(p)) 
        {
            points.push_back(p);
        }
    }

    unsigned long size() const // кол-во точек на сцене
    {
        return points.size();
    }

    const Point& operator[](int index) const .
    {
        return points[index];
    }
};

// Пример использования
int main() 
{
    Scene scene;
    scene.append(Point(1, 2, 3));
    scene.append(Point(4, 5, 6));
    scene.append(Point(7, 8, 9));

    for (int i = 0; i < scene.size(); i++) {
        const Point& p = scene[i];
        cout << "Point " << i << ": (" << p.x() << ", " << p.y() << ", " << p.z() << ")" << endl;
    }

    return 0;
}