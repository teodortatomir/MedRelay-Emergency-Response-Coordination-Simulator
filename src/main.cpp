#include "medrelay/HospitalRecommender.hpp"
#include "medrelay/ReservationService.hpp"

#include <iostream>
#include <vector>

int main() {
    using namespace medrelay;

    const std::vector<Hospital> hospitals{
        {1, "Hospital A", {2.0, 3.0},
            {Specialty::GeneralEmergency, Specialty::Trauma}, 3},
        {2, "Hospital B", {5.0, 1.0},
            {Specialty::Cardiology}, 2},
        {3, "Hospital C", {1.0, 1.0},
            {Specialty::Cardiology}, 0}
    };

    const Incident incident{
        101,
        {0.0, 0.0},
        Specialty::Cardiology,
        "Simulated incident"
    };

    ReservationService reservationService(hospitals);
    const HospitalRecommender recommender;

    const auto result = recommender.recommend(
        incident,
        reservationService.getHospitals()
    );

    if(!result) {
        std::cout << "No eligible hospital found.\n";
        return 0;
    }

    std::cout << "Hospital ID: " << result->hospitalId << '\n'
              << "Distance: " << result->distanceKm << " km\n"
              << "Reason: " << result->reason << '\n';

    const auto reservation = reservationService.reserve(
        incident.id,
        result->hospitalId
    );

    if(!reservation) {
        std::cout << "Reservation failed.\n";
        return 1;
    }

    std::cout << "\nReservation created: " << reservation->id << '\n';

    const auto duplicate = reservationService.reserve(
        incident.id,
        result->hospitalId
    );

    std::cout << "Duplicate reservation rejected: "
              << std::boolalpha << !duplicate.has_value() << '\n';

    // Anulează rezervarea și eliberează locul.
    const bool cancelled = reservationService.cancel(reservation->id);

    std::cout << "Cancellation successful: " << cancelled << '\n';

    // O a doua anulare nu trebuie să elibereze încă un loc.
    const bool cancelledAgain = reservationService.cancel(reservation->id);

    std::cout << "Second cancellation rejected: "
              << !cancelledAgain << '\n';

    std::cout << "\nFinal hospital availability:\n";

    for (const Hospital& hospital : reservationService.getHospitals()) {
        std::cout << hospital.name << ": "
                  << hospital.availableBeds << " available beds\n";
    }

    return 0;
}