#pragma once

#include <boost/signals2.hpp>

#include "../../benchmark.hpp"

class Bs2_st
{
    boost::signals2::scoped_connection reg;
  
    NOINLINE(void handler(Rng& rng))
    {
        volatile std::size_t a = rng(); (void)a;
    }

    public:

    using Signal =
        typename boost::signals2::signal_type
        <
            void(Rng&),
            boost::signals2::keywords::mutex_type<boost::signals2::dummy_mutex>
          >::type;

    template <typename Subject, typename Foo>
    static void connect_method(Subject& subject, Foo& foo)
    {
        foo.reg =
          subject.connect
          (std::bind(&Foo::handler, &foo, std::placeholders::_1));
    }
    template <typename Subject>
    static void emit_method(Subject& subject, Rng& rng)
    {
        subject(rng);
    }

    // Used for switching policies at runtime
    static void initialize();

    static void validate_assert(std::size_t);
    static double construction(std::size_t, std::size_t);
    static double destruction(std::size_t, std::size_t);
    static double connection(std::size_t, std::size_t);
    static double disconnect(std::size_t, std::size_t);
    static double reconnect(std::size_t, std::size_t);
    static double emission(std::size_t, std::size_t);
    static double combined(std::size_t, std::size_t);

    // NOT IMPLEMENTED FOR THIS LIB
    static double threaded(std::size_t, std::size_t);

    // The following is used for report outputs
    static constexpr const char* C_LIB_NAME = "Boost Signals2 st";
    static constexpr const char* C_LIB_SOURCE_URL = "http://www.boost.org/doc/libs/1_58_0/doc/html/signals2.html";
    static constexpr const char* C_LIB_FILE = "benchmark_bs2_st";
    static constexpr const char* C_LIB_IS_HEADER_ONLY = "-";
    static constexpr const char* C_LIB_DATA_STRUCTURE = "?";
    static constexpr const char* C_LIB_IS_THREAD_SAFE = "-";

    static constexpr const std::size_t C_LIB_SIZEOF_SIGNAL = sizeof(Signal);
};
