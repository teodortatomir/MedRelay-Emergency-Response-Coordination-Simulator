#pragma once

#include "medrelay/Location.hpp"
#include "medrelay/Specialty.hpp"
#include <string>
#include <vector>

namespace medrelay {
    struct Hospital {
        int id;
        std::string name;
        Location location;
        std::vector<Specialty> specialties;
        int availableBeds;
    };
}