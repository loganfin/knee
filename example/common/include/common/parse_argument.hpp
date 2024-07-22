#pragma once

#include <algorithm>
#include <functional>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace common {

////////////////////////////////////////////////////////////////////////////////
template <typename T>
T parse_argument(
    std::vector<std::string> const& argv,
    std::string primary_option,
    std::optional<std::string> secondary_option,
    std::optional<std::function<void(std::string, std::optional<std::string>)>>
        error_handler
)
{
    T retval;

    auto primary_it = std::ranges::find(argv, primary_option);

    if (primary_it != argv.end() && primary_it++ != argv.end()) {
        std::stringstream{*primary_it} >> retval;
        return retval;
    } else if (secondary_option) {
        auto secondary_it = std::ranges::find(argv, secondary_option.value());

        if (secondary_it != argv.end() && secondary_it++ != argv.end()) {
            std::stringstream{*secondary_it} >> retval;
            return retval;
        } else {
            if (error_handler) {
                error_handler.value()(primary_option, secondary_option);
            }
        }
    } else {
        if (error_handler) {
            error_handler.value()(primary_option, secondary_option);
        }
    }

    return {};
}

////////////////////////////////////////////////////////////////////////////////
bool flag_exists(
    std::vector<std::string> const& argv,
    std::string primary_option,
    std::optional<std::string> secondary_option
);

} // namespace common
