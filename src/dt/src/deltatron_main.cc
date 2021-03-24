#include <dt/deltatron.hh>

#include <exception>
#include <iostream>

int main(int const ac, char const* const* const av, char const* const* const ep) {
  try {
    dt::deltatron const _(ac, av, ep);
    _.run();

  } catch (dt::termflag_passed const& tfp) {
    std::cerr << tfp.what() << std::endl;

  } catch (std::exception const& e) {
    std::cerr << "std::exception caught in main: " << e.what() << std::endl;

  } catch (...) {
    std::cerr << "unknown type caught in main" << std::endl;

  }
}
