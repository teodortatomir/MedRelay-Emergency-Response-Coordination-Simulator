#pragma once

#include "medrelay/Hospital.hpp"
#include "medrelay/Incident.hpp"
#include "medrelay/Recommendation.hpp"
#include <optional>
#include <vector>

namespace medrelay {
    class HospitalRecommender {

    public:
        std::optional<Recommendation> recommend(
            const Incident& incident,
            const std::vector<Hospital>& hospitals
        ) const;
    };

}