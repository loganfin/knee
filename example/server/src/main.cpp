#include "parse_arguments.hpp"

// #include "locket/socket.hpp"

#include <print>

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    Arguments args;

    try {
        args = parse_arguments(argc, argv);
    } catch (std::exception const& exception) {
        std::println("{}", exception.what());
        return EXIT_FAILURE;
    }

    std::println("port: {}", args.port);

    // auto socket = locket::Socket{args.ip_address, args.port};
}
