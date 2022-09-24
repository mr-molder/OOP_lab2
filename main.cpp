#include <iostream>
#include "cassini.h"
#include <cmath>

int main() {

    Lab2::Point F1(0, 0);
    Lab2::Point F2(13, 2.8);

    std::cout << "Enter curve parameter 'a':" << std::endl;
    double a;
    bool success = false;
    Lab2::Cassini curve (F1, F2, 0);
    while(!success) {
        try {
            std::cin >> a;
            //std::cout << a << std::endl;
            curve = Lab2::Cassini(F1, F2, a);
            success = true;
        } catch (std::exception &ex) {
            std::cout << "An error occurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    int polar_angle;
    int error;
        std::cout << "Enter polar angle:" << std::endl;
        std::cin >> polar_angle;
        error = std::cin.good();
        try {
            double distance = curve.distance(polar_angle);
            std::cout << "The distant to point at polar angle " << polar_angle << " is " << distance << std::endl;
        } catch (std::exception &ex) {
            std::cout << "An error occurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        std::cout << "The shape of the curve is: ";
        switch (curve.shape()) {
            case Lab2::Cassini::Shape::lemniscate:
                std::cout << "lemniscate" << std::endl;
                break;
            case Lab2::Cassini::Shape::oval:
                std::cout << "oval" << std::endl;
                break;
            case Lab2::Cassini::Shape::inflection:
                std::cout << "inflection" << std::endl;
                break;
            case Lab2::Cassini::Shape::pair:
                std::cout << "pair" << std::endl;
                break;
        }
        try {
            double r = curve.radius(polar_angle);
        std::cout << "radius of curvature: " << r << std::endl;
        } catch (std::exception &ex) {
            std::cout << "An error occurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }

        Lab2::PolarPoint *polarPoint = curve.inflection_points();

        std::cout << "inflection points coords: " << polarPoint->rho << "; " << polarPoint->phi << std::endl;

        std::cout << "formula of the curve: " << curve.equation() << std::endl;

        delete polarPoint;

    return 0;
}

