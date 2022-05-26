/************************************************************************************
 *
 * D++, A Lightweight C++ library for Discord
 *
 * Copyright 2021 Craig Edwards and D++ contributors
 * (https://github.com/brainboxdotcc/DPP/graphs/contributors)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ************************************************************************************/
#pragma once
#include <dpp/permissions.h>

namespace dpp {

template<typename T> permission::permission(T v) : value(v) {};

permission::permission() : permission(0) {}

permission::operator uint64_t() const {
	return value;
}

permission::operator uint64_t &() {
	return value;
}

bool permission::has(uint64_t p) const {
	return (value & p);
}

void permission::add(uint64_t p) {
	value |= p;
}

void permission::set(uint64_t p) {
	value = p;
}

void permission::remove(uint64_t p) {
	value &= ~p;
}

}