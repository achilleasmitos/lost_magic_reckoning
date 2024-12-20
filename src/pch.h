#pragma once

#include <functional>
// see comments on https://stackoverflow.com/questions/66408981/iostream-and-define-stdc-want-secure-lib-0-results-in-error-c2039-sprin
// not necessary if it has other STL includes above (like <functional>)
#pragma warning(push)
#pragma warning(disable : 4668)
#include <iostream>
#pragma warning(pop)
#include <memory>
#include <optional>
