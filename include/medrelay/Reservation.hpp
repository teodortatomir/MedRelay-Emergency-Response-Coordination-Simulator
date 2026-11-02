enum class ReservationStatus {
    Active,
    Cancelled
};

struct Reservation {
    int id;
    int incidentId;
    int hospitalId;
    ReservationStatus status;
};