#include "common/parse_argument.hpp"

namespace common {

////////////////////////////////////////////////////////////////////////////////
bool flag_exists(
    std::vector<std::string> const& argv,
    std::string primary_option,
    std::optional<std::string> secondary_option
)
{
    auto primary_it = std::ranges::find(argv, primary_option);
    auto secondary_it = std::ranges::find(argv, secondary_option.value());

    return primary_it != argv.end() || secondary_it != argv.end();
}

} // namespace common
