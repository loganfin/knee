#include "locket/socket.hpp"

namespace locket {

////////////////////////////////////////////////////////////////////////////////
Socket::Socket(std::string const& ip_address, int port)
    : ip_address_{ip_address}, port_{port}
{
}

} // namespace locket
