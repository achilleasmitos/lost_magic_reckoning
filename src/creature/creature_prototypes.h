#pragma once

#include "./creature.h"
#include <memory>

using CreatureUniquePtr = std::unique_ptr<Creature>;
using CreatureSharedPtr = std::shared_ptr<Creature>;
using CreatureWeakPtr = std::weak_ptr<Creature>;
