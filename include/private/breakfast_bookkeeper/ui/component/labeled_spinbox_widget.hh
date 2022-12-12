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

#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
//
#include <QtCore/QObject>
#include <QtCore/QPointer>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {

class LabeledSpinBoxWidget final : public QWidget {
  Q_OBJECT
 public:
  explicit LabeledSpinBoxWidget(QWidget* const parent = nullptr) noexcept;

  QPointer<QSpinBox> getSpinBox() const noexcept;
  QPointer<QLabel> getLabel() const noexcept;

 private:
  QPointer<QHBoxLayout> getLayout() const noexcept;

  void generateView();
  void generateLayout();
  void generateSpinBox();

  QPointer<QSpinBox> spin_box_;
  QPointer<QLabel> label_;
};

}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
