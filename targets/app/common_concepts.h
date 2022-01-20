
#pragma once

#include <concepts>

template<typename TEnum>
concept IsEnum = std::is_enum_v<TEnum>;

template<typename TScalar>
concept IsNumber = std::integral<TScalar> || std::floating_point<TScalar>;