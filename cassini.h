//
// Created by santas_molderras on 18.09.22.
//

#ifndef LAB2_CASSINI_H
#define LAB2_CASSINI_H

#include <math.h>
#include <exception>
#include <stdexcept>
#include <limits>

namespace Lab2 {

    struct Point{
        double x, y;
        explicit Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
    };

    struct PolarPoint {
        double rho, phi;
        explicit PolarPoint (double _rho = 0, double _phi = 0) :rho(_rho), phi(_phi){}
    };

    class Cassini {
    private:
        Point F1, F2;
        double a;
    public:
        enum class Shape {pair, lemniscate, inflection, oval, undefined};
        Cassini(const Point &_F1, const Point &_F2, double _a);
        Cassini(double x1, double y1, double x2, double y2, double _a);

        Cassini& setF1(const Point &_F1);
        Cassini& setF2(const Point &_F2);
        Cassini& setA(double a);

        Point getF1() const { return F1; }
        Point getF2() const { return F2; }
        double getA() const { return a;  }

        /*
         * Вернуть расстояние до центра в полярной системе координат в зависимости от угла для
         * точки принадлежащей линии Кассини.
         */
        double distance(double phi) const;

        /*
         * Вернуть тип формы линии Кассини (два отдельных овала, лемниската, с перегибами,
         * овальная)
         */
        Shape shape() const;

        /*
         * Вернуть радиус кривизны в зависимости от угла полярного радиуса.
         */
        double radius(double phi) const;

        /*
         * Вернуть координаты точек перегиба линии Кассини.
         */
        PolarPoint *inflection_points() const;

        /*
         * Вернуть текстовое представление уравнения линии Кассини в декартовой системе.
         */
        std::string equation() const;
    };

}

#endif //LAB2_CASSINI_H
