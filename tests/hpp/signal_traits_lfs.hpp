#pragma once

#include <CppFakeIt/libfastsignals/include/lfs_connection.h>
#include <CppFakeIt/libfastsignals/include/signal.h>

struct signal_traits_lfs
{
  static constexpr bool has_signal_empty_test = true;
  static constexpr bool has_connection_connected_test = true;
  static constexpr bool has_disconnect_all = true;
  static constexpr bool has_swap = true;
  static constexpr bool will_deadlock_if_recursively_modified = false;
  static constexpr bool is_intrusive = false;
  
  template<typename Signature>
  using signal = is::signals::signal<Signature>;

  using connection = is::signals::connection;

  static void initialize() {}
  static void terminate() {}
  
  template<typename Signal>
  static bool empty(Signal& s)
  {
    return s.empty();
  }

  template<typename Signal, typename F>
  static connection connect(Signal& s, F&& f)
  {
    return s.connect(std::forward<F>(f));
  }

  template<typename Signal, typename... Args>
  static void trigger(Signal& s, Args&&... args)
  {
    s(std::forward<Args>(args)...);
  }

  static bool connected(const connection& c)
  {
    return c.connected();
  }
  
  template<typename Signal>
  static void disconnect(Signal& s, connection& c)
  {
    c.disconnect();
  }
  
  template<typename Signal>
  static void disconnect_all_slots(Signal& s)
  {
    s.disconnect_all_slots();
  }
  
  template<typename Signal>
  static void swap(Signal& s1, Signal& s2)
  {
    s1.swap(s2);
  }
};

