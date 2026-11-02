#include "medrelay/ReservationService.hpp"

#include <algorithm>
#include <utility>

namespace medrelay {
    ReservationService::ReservationService(std::vector<Hospital> hospitals) : hospitals_(std::move(hospitals)) {}

    std::optional<Reservation> ReservationService::reserve(int incidentId, int hospitalId) {
        const auto existingReservation = std::find_if(reservations_.begin(), reservations_.end(),
            [incidentId](const Reservation& reservation) {
                return reservation.incidentId == incidentId && reservation.status == ReservationStatus::Active;
            }
        );

        if (existingReservation != reservations_.end()) 
            return std::nullopt;

        const auto hospital = std::find_if(hospitals_.begin(), hospitals_.end(),
            [hospitalId](const Hospital& candidate) {
                return candidate.id == hospitalId;
            }
        );

        if (hospital == hospitals_.end() || hospital->availableBeds <= 0) 
            return std::nullopt;

        const Reservation reservation{nextReservationId_, incidentId, hospitalId, ReservationStatus::Active};

        reservations_.push_back(reservation);
        
        --hospital->availableBeds;
        nextReservationId_++;

        return reservation;
    }

    bool ReservationService::cancel(int reservationId) {
        const auto reservation = std::find_if(reservations_.begin(), reservations_.end(),
            [reservationId](const Reservation& candidate) {
                return candidate.id == reservationId;
            }
        );

        if (reservation == reservations_.end() || reservation->status != ReservationStatus::Active) 
            return false;

        const auto hospital = std::find_if(hospitals_.begin(), hospitals_.end(),
            [hospitalId = reservation->hospitalId](const Hospital& candidate) {
                return candidate.id == hospitalId;
            }
        );

        if (hospital == hospitals_.end()) 
            return false;

        reservation->status = ReservationStatus::Cancelled;
        ++hospital->availableBeds;

        return true;
    }

    const std::vector<Hospital>& ReservationService::getHospitals() const {
        return hospitals_;
    }

    const std::vector<Reservation>& ReservationService::getReservations() const {
        return reservations_;
    }
}