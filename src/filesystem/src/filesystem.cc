#include <dt/filesystem.hh>
#include <dt/filesystem_imp.hh>

dt::filesystem::filesystem(command const& cmd)
: _filesystem(std::make_unique<filesystem_imp>(cmd)) {}

dt::filesystem::~filesystem() noexcept {}

dt::directory dt::filesystem::root() const noexcept
{ return _filesystem->root(); }
