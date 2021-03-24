#include <dt/fs.hh>
#include <dt/fs_imp.hh>

dt::fs::fs(cmd const& c)
: _fs(std::make_unique<fs_imp>(c)) {}

dt::fs::~fs() noexcept {}

dt::directory dt::fs::root() const noexcept
{ return _fs->root(); }
