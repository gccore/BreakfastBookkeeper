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

#include <QtCore/QPointer>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class RawDateWidget;
class ListWidget;

class InsertPageWidget final : public QWidget {
  Q_OBJECT

  using Layout = QVBoxLayout;

 public:
  explicit InsertPageWidget(QWidget* const parent = nullptr) noexcept;

 private:
  QPointer<Layout> getLayout() const;

  void generateView();
  void generateLayout();
  void generateCurrentDay();
  void generateParticipantList();

  QPointer<RawDateWidget> current_day_;
  QPointer<ListWidget> participant_list_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
