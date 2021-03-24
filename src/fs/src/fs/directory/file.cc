#include <dt/fs/directory/file.hh>

dt::file::file(std::string const& name, std::string const& data)
: _name(name),
  _data(data) {}

dt::file::~file() noexcept {}
