//
// Created by santas_molderras on 18.09.22.
//

#include "cassini.h"

namespace Lab2 {

    Cassini::Cassini(const Point &_F1, const Point &_F2, double _a): F1{_F1}, F2{_F2}, a{_a} {
        if (a < 0) {
            throw std::runtime_error("invalid a");
        }
    }

    Cassini::Cassini(double x1, double y1, double x2, double y2, double _a) : F1{x1, y1}, F2{x2, y2}, a{_a} {
        if (a < 0) {
            throw std::runtime_error("invalid a");
        }
    }

    Cassini& Cassini::setA(double _a) {
        if (_a < 0) {
            throw std::runtime_error("invalid a");
        }
        a = _a;

        return *this;
    }

    Cassini& Cassini::setF1(const Point &_F1) {
        return *this;
    }

    Cassini& Cassini::setF2(const Point &_F2) {
        return *this;
    }

    double Cassini::distance(double phi) const {
        auto s = shape();
        if (s == Shape::pair || s == Shape::lemniscate) {
            throw std::runtime_error("impossible to find distance in this case.");
        }
        double D, c2, r2;
        c2 = (pow((F1.x - F2.x), 2) + pow((F1.y - F2.y), 2)) / 4;
        D = 4 *c2*c2* cos(2*phi) * cos(2*phi) - 4 * (pow(a, 4) - c2 * c2);
        r2 = ((2 *c2*cos(2*phi)) + sqrt(abs(D))) / 2;
        return sqrt(r2);
    }

    Cassini::Shape Cassini::shape() const {

        double c;
        c = sqrt((pow((F1.x - F2.x), 2) + pow((F1.y - F2.y), 2))) / 2;

        if (a == 0 && c != 0) {
            return Shape::pair;
        }
        if (0 < a && a < c) {
            return Shape::pair;
        }
        if (a == c) {
            return Shape::lemniscate;
        }
        if (c < a && a < c * sqrt(2)) {
            return Shape::inflection;
        }
        if (a >= c * sqrt(2)) {
            return Shape::oval;
        }
        return Shape::undefined;
    }

    double Cassini::radius(double phi) const {
        double c = sqrt((pow((F1.x - F2.x), 2) + pow((F1.y - F2.y), 2))) / 2;
        double rho = distance(phi);
        double r = pow(a, 2) * rho / (pow(rho, 2) + pow(c, 2) * cos(2 * phi));
        return r;
    }

    std::string Cassini::equation() const {
        double c = sqrt((pow((F1.x - F2.x), 2) + pow((F1.y - F2.y), 2))) / 2;
        std::string answer = "(x^2 + y^2)^2 - 2" + std::to_string(c) + "^2 * (x^2 - y^2) = " +
                std::to_string(a) + "^4 - " + std::to_string(c) + "^4";
        return answer;
    }

    PolarPoint *Cassini::inflection_points() const {
        double c = sqrt((pow((F1.x - F2.x), 2) + pow((F1.y - F2.y), 2))) / 2;
        double rho = pow(abs(pow(a, 4) - pow(c, 4)) / 3, 0.25);

        double phi = 0.5 * acos((sqrt(abs(pow(a, 4) / pow(c, 4) - 1) / 3)) );
        auto *pp = new PolarPoint;
        pp->rho = rho;
        pp->phi = phi;
        return pp;
    }
}