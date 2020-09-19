#pragma once

#include "PerEnum.hpp"

#include <fmt/format.h>

#include <optional>
#include <string_view>

// Sector types.
// Used in #ROOMS so value is important.
enum class SectorType {
    Inside = 0,
    City = 1,
    Field = 2,
    Forest = 3,
    Hills = 4,
    Mountain = 5,
    SwimmableWater = 6,
    NonSwimmableWater = 7,
    // 8 is unused
    Air = 9,
    Desert = 10,
};

static constexpr int SectorType_Max = 11; // TODO ideally find a nice way to make this better
template <typename T>
using PerSectorType = PerEnum<SectorType, T, SectorType_Max>;

std::string_view to_string(SectorType type);

// Ideally we'd make anything with a "to_string" format, but I couldn't get that to work...
template <>
struct fmt::formatter<SectorType> : public formatter<std::string_view> {
    template <typename FormatContext>
    auto format(SectorType sector_type, FormatContext &ctx) {
        return formatter<std::string_view>::format(to_string(sector_type), ctx);
    }
};

std::optional<SectorType> try_get_sector_type(int value);
