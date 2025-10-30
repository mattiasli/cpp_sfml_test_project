#pragma once
#include <cstdint>
#include "../core/Constants.hpp"

namespace graphics {

    struct EntityVisualKey
    {
        constants::EntityType entityType;
        constants::EntityState entityState;
        constants::Direction direction;

        bool operator==(const EntityVisualKey& other) const
        {
            return entityType == other.entityType &&
                   entityState == other.entityState &&
                   direction == other.direction;
        }
    };

    struct EntityVisualKeyHash
    {
        std::uint64_t operator()(const EntityVisualKey& entityVisualKey) const
        {
            return static_cast<std::uint64_t>(entityVisualKey.entityType) * 1000000
                   + static_cast<std::uint64_t>(entityVisualKey.entityState) * 1000
                   + static_cast<std::uint64_t>(entityVisualKey.direction);
        }
    };
}