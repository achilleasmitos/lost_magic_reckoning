#pragma once

#include <memory>

class Creature;
using CreatureUniquePtr = std::unique_ptr<Creature>;
using CreatureSharedPtr = std::shared_ptr<Creature>;
using CreatureWeakPtr = std::weak_ptr<Creature>;
