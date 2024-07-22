#include "parse_arguments.hpp"

#include "common/parse_argument.hpp"

#include <format>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

////////////////////////////////////////////////////////////////////////////////
auto constexpr port_primary{"--port"};
auto constexpr port_secondary{"-p"};
auto constexpr port_description{"Port to bind to."};

auto constexpr help_primary{"--help"};
auto constexpr help_secondary{"-h"};
auto constexpr help_description{"Print help menu."};

auto const help_menu{std::format(
    "Usage: server [options]\n"
    "  {}, {}: {}\n"
    "  {}, {}: {}",
    port_secondary,
    port_primary,
    port_description,
    help_secondary,
    help_primary,
    help_description
)};

////////////////////////////////////////////////////////////////////////////////
template <typename T>
T parse_required_argument(
    std::vector<std::string> const& argv,
    std::string primary_option,
    std::optional<std::string> secondary_option = std::nullopt
)
{
    return common::parse_argument<T>(
        argv,
        primary_option,
        secondary_option,
        [](std::string const& primary_option,
           std::optional<std::string> const& secondary_option) {
            if (secondary_option) {
                throw std::runtime_error(std::format(
                    "Please provide {} or {}\n\n{}",
                    primary_option,
                    secondary_option.value(),
                    help_menu
                ));
            } else {
                throw std::runtime_error(std::format(
                    "Please provide {}\n\n{}", primary_option, help_menu
                ));
            }
        }
    );
}

} // namespace

////////////////////////////////////////////////////////////////////////////////
Arguments parse_arguments(int argc, char** argv)
{
    auto args = std::vector<std::string>(argv, argv + argc);

    auto help = common::flag_exists(args, help_primary, help_secondary);

    if (help) {
        throw std::runtime_error(std::format("{}", help_menu));
    }

    return {parse_required_argument<int>(args, port_primary, port_secondary)};
}
