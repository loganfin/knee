#pragma once

#include <string>

////////////////////////////////////////////////////////////////////////////////
struct Arguments {
    std::string ip_address;
    int port;
};

////////////////////////////////////////////////////////////////////////////////
Arguments parse_arguments(int argc, char** argv);
