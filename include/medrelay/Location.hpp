#pragma once

namespace medrelay {
    struct Location {
        double xKm;
        double yKm;
    };

    double distanceKm(const Location& first, const Location& second);
}