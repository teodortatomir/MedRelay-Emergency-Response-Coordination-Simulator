#include "medrelay/HospitalRecommender.hpp"
#include <iostream>
#include <vector>

int main() {
    using namespace medrelay;

    const std::vector<Hospital> hospitals {
        {1, "Hospital A", {2.0, 3.0},
            {Specialty::GeneralEmergency, Specialty::Trauma}, 3},
        {2, "Hospital B", {5.0, 1.0},
            {Specialty::Cardiology}, 2},
        {3, "Hospital C", {1.0, 1.0},
            {Specialty::Cardiology}, 0}
    };

    const Incident incident {
        101,
        {0.0, 0.0},
        Specialty::Cardiology,
        "Simulated incident"
    };

    const HospitalRecommender recommender;
    const auto result = recommender.recommend(incident, hospitals);

    if(!result) {
        std::cout<<"No eligible hospital found.\n";
        return 0;
    }

    std::cout<<"Hospital ID: "<<result->hospitalId<<'\n'
              <<"Distance: "<<result->distanceKm<<" km\n"
              <<"Reason: "<<result->reason<<'\n';
}