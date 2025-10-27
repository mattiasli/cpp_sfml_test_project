#pragma once
#include <cstdint>
#include "../core/Constants.hpp"

namespace graphics {

    struct AnimationKey
    {
        constants::EntityType entityType;
        constants::EntityState entityState;
        constants::Direction direction;

        bool operator==(const AnimationKey& other) const
        {
            return entityType == other.entityType &&
                   entityState == other.entityState &&
                   direction == other.direction;
        }
    };

    struct AnimationKeyHash
    {
        std::uint64_t operator()(const AnimationKey& animationKey) const
        {
            return static_cast<std::uint64_t>(animationKey.entityType) * 1000000
                   + static_cast<std::uint64_t>(animationKey.entityState) * 1000
                   + static_cast<std::uint64_t>(animationKey.direction);
        }
    };
}