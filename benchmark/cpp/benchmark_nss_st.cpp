#include "../hpp/benchmark_nss_st.hpp"

NOINLINE(void Nss_st::initialize())
{
    // NOOP
}
NOINLINE(void Nss_st::validate_assert(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::validation_assert(N);
}
NOINLINE(double Nss_st::construction(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::construction(N);
}
NOINLINE(double Nss_st::destruction(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::destruction(N);
}
NOINLINE(double Nss_st::connection(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::connection(N);
}
NOINLINE(double Nss_st::disconnect(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::disconnect(N);
}
NOINLINE(double Nss_st::reconnect(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::reconnect(N);
}
NOINLINE(double Nss_st::emission(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::emission(N);
}
NOINLINE(double Nss_st::combined(std::size_t N))
{
    return Benchmark<Signal, Nss_st>::combined(N);
}
NOINLINE(double Nss_st::threaded(std::size_t N))
{
    // NOT IMPLEMENTED FOR THIS LIB
    return 0.0;
}
