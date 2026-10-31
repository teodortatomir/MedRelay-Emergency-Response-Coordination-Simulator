#include "medrelay/HospitalRecommender.hpp"
#include <algorithm>
#include <optional>

namespace medrelay {

    std::optional<Recommendation> HospitalRecommender::recommend(const Incident& incident, const std::vector<Hospital>& hospitals) const {
        std::optional<Recommendation> best;

        for(const Hospital& hospital : hospitals) {
            if(hospital.availableBeds <= 0)
                continue;
            
            const std::vector<Specialty>& specialities = hospital.specialties;
            if(std::find(specialities.begin(), specialities.end(), incident.requiredSpecialty) != specialities.end()) {
                const double distance = distanceKm(incident.location, hospital.location);

                if(!best || distance < best->distanceKm
                    || (distance == best->distanceKm && hospital.id < best->hospitalId)) {
                    best = Recommendation{hospital.id, distance, "Closest eligible hospital with an available bed."};
                }
            }
        }

        return best;
    }

}