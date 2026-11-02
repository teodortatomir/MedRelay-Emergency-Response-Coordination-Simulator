#pragma once

#include "medrelay/Hospital.hpp"
#include "medrelay/Reservation.hpp"

#include <optional>
#include <vector>

namespace medrelay {
    class ReservationService {
    public:
        explicit ReservationService(std::vector<Hospital> hospitals);

        std::optional<Reservation> reserve(int incidentId, int hospitalId);

        bool cancel(int reservationId);

        const std::vector<Hospital>& getHospitals() const;

        const std::vector<Reservation>& getReservations() const;

    private:
        std::vector<Hospital> hospitals_;
        std::vector<Reservation> reservations_;
        int nextReservationId_ = 1;
    };
}