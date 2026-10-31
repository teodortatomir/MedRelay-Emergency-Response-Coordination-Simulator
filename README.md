# MedRelay

A C++17 emergency response coordination simulator. MedRelay aims to connect incident reporting, hospital selection, ambulance routing, and intervention records.

## Current Features

- Models incidents, hospitals, locations, and medical specialties.
- Filters hospitals by required specialty and available beds.
- Recommends the nearest eligible hospital using straight-line distance.
- Breaks distance ties by hospital ID.
- Reports when no eligible hospital is available.

## Build and Run

Requires CMake 3.16+ and a C++17-compatible compiler.

```bash
cmake -S . -B build
cmake --build build
./build/medrelay
```

## Planned Features

- Bed reservation and capacity management.
- Call transcription with operator review.
- Ambulance routing.
- Crew updates and intervention reports.
