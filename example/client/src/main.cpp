#include "parse_arguments.hpp"

// #include "locket/socket.hpp"

#include <print>

int main(int argc, char** argv)
{
    Arguments args;

    try {
        args = parse_arguments(argc, argv);
    } catch (std::exception const& exception) {
        std::println("{}", exception.what());
        return EXIT_FAILURE;
    }

    // auto socket = locket::Socket{};
}
