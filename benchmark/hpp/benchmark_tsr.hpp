#pragma once

#include "../lib/tripleslash/rocket/rocket.hpp"

#include "../../benchmark.hpp"

class Tsr : rocket::trackable
{
    NOINLINE(void handler(Rng& rng))
    {
        volatile std::size_t a = rng(); (void)a;
    }

    public:

    using Signal = rocket::thread_safe_signal<void(Rng&)>;

    template <typename Subject, typename Foo>
    static void connect_method(Subject& subject, Foo& foo)
    {
        subject.connect(foo, &Foo::handler);
    }
    template <typename Subject>
    static void emit_method(Subject& subject, Rng& rng)
    {
        // msvc compilation error code C664
        // _Ret std::_Func_class<_Ret,Rng &>::operator ()(Rng &) const': cannot convert argument 1 from 'const Rng' to 'Rng &'
        // rocket.hpp line 3452
        //subject(rng);
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
    static double threaded(std::size_t, std::size_t);

    static constexpr const char* C_LIB_NAME = "* rocket";
    static constexpr const char* C_LIB_SOURCE_URL = "https://github.com/tripleslash/rocket";
    static constexpr const char* C_LIB_FILE = "benchmark_tsr";
    static constexpr const char* C_LIB_IS_HEADER_ONLY = "X";
    static constexpr const char* C_LIB_DATA_STRUCTURE = "intrusive list";
    static constexpr const char* C_LIB_IS_THREAD_SAFE = "X";

    static constexpr const std::size_t C_LIB_SIZEOF_SIGNAL = sizeof(Signal);
};
