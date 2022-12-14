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

#define REQUIRED_LAYOUT_MESSAGE "We don't have one"

#define LAYOUT_IS_REQUIRED() assert(getLayout() && REQUIRED_LAYOUT_MESSAGE)
#define QWIDGET_LAYOUT_IS_REQUIRED() \
  assert(this->QWidget::layout() && REQUIRED_LAYOUT_MESSAGE)
#define CONDITION
#define ERROR_MESSAGE
#define REQUIRED(condition, message) assert(condition&& message)
