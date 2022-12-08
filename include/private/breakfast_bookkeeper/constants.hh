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

#include <QtCore/QSize>
//
#include <cstdint>

namespace gccore {
namespace breakfast_bookkeeper {
namespace constants {
namespace ui {
std::int32_t constexpr kSomeDefaultMargin = 2;
QSize constexpr kMinimumSize = QSize(800, 600);
}  // namespace ui
namespace names {
char const* const kApplicationName = "Breakfast Bookkeeper";
}  // namespace names
}  // namespace constants
}  // namespace breakfast_bookkeeper
}  // namespace gccore
