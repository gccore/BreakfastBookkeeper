/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * @gccore
 * g1999raemzani@gmail.com
 */

#pragma once

#include <QtCore/QSize>
//
#include <cstdint>

namespace gccore {
namespace breakfast_bookkeeper {
namespace constants {
namespace ui {
std::int32_t constexpr kSomeDefaultMargin = 2;
std::uint32_t constexpr kMinimumYear = 1000;
std::uint32_t constexpr kMaximumYear = 2000;
std::uint32_t constexpr kMinimumMonth = 1;
std::uint32_t constexpr kMaximumMonth = 12;
std::uint32_t constexpr kMinimumDay = 1;
std::uint32_t constexpr kMaximumDay = 31;
QSize constexpr kMinimumSize = QSize(800, 600);
}  // namespace ui
namespace names {
char const* const kApplicationName = CURRENT_PROJECT_NAME;
char const* const kApplicationVersion = CURRENT_PROJECT_VERSION;
char const* const kApplicationOrganization = CURRENT_PROJECT_ORGANIZATION;
char const* const kDateDisplayFormat = "yyyy-MM-dd";
char const* const kYearLabel = "Y: ";
char const* const kMonthLabel = "M: ";
char const* const kDayLabel = "D: ";
char const* const kCopyAction = "Copy Date";
}  // namespace names
}  // namespace constants
}  // namespace breakfast_bookkeeper
}  // namespace gccore
