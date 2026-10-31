#pragma once

#include "medrelay/Location.hpp"
#include "medrelay/Specialty.hpp"
#include <string>

namespace medrelay {
    struct Incident {
        int id;
        Location location;
        Specialty requiredSpecialty;
        std::string description;
    };
}