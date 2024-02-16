# Chrono in C++
A C++ header called <chrono> offers a number of classes and methods for working with time. It is present in C++11 and subsequent versions and is a component of the C++ Standard Template Library (STL).
The three primary clock types offered by <chrono> are system_clock, steady_clock, and high_resolution_clock. There are several ways to measure time with these clocks.
The system-wide real-time wall clock is represented by system_clock. The system's time modifications have an impact on it.
A clock that increases monotonically and is unaffected by shifts in the system time is denoted by the term steady_clock.
The clock on the system with the smallest tick period is called high_resolution_clock.
The Chrono library is utilized for managing time and dates. This library was created to handle the possibility that timers and clocks may vary between systems, allowing for gradual precision improvements. What makes chrono special is that it decouples duration and a point in time (a "timepoint") from particular clocks, so offering a concept that is neutral with regard to precision. Both a header and a sub-namespace are named chrono: With the exception of the common_type specializations, every element in this header is declared under the std::chrono namespace rather than the std namespace, unlike the majority of the standard library. This header's components all relate to time. Three ideas are primarily used to do this:<br />
Using std::chrono::literals namespace <br />
- for 2seconds use 2s.
- for 20 milliseconds use 20ms.
- for 50 microseconds use 50us etc.