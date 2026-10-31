#include "medrelay/Location.hpp"
#include <cmath>

namespace medrelay {
    double distanceKm(const Location& first, const Location& second) { // Calculates the distance between two locations
        return std::hypot(first.xKm - second.xKm, first.yKm - second.yKm);
    }
}