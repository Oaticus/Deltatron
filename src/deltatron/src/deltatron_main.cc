#include <dt/deltatron.hh>

#include <exception>
#include <iostream>

int main(int const arg_size, char const* const* const arg_list, char const* const* const env_list) {
  try {
    dt::deltatron({.arg_size = arg_size, .arg_list = arg_list, .env_list = env_list}).run();

  } catch (dt::termflag_passed const& term_flag) {
    std::cerr << term_flag.what() << std::endl;

  } catch (std::exception const& e) {
    std::cerr << "std::exception caught in main: \"" << e.what() << '"' << std::endl;

  } catch (...) {
    std::cerr << "unknown type caught in main" << std::endl;

  }
}
