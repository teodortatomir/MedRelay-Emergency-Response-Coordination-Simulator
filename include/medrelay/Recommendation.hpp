#pragma once

#include <string>

namespace medrelay {
    struct Recommendation {
        int hospitalId;
        double distanceKm;
        std::string reason;
    };
}