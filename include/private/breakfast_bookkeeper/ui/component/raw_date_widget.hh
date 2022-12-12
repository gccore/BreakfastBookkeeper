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

#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
//
#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtCore/QPoint>
#include <QtCore/QPointer>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class LabeledSpinBoxWidget;

class RawDateWidget final : public QWidget {
  Q_OBJECT
 public:
  explicit RawDateWidget(QWidget* const parent = nullptr) noexcept;

 private:
  QPointer<QHBoxLayout> getLayout() const noexcept;

  void addAdditionalSpacer();

  void generateView();
  void generateLayout();
  void generateYear();
  void generateMonth();
  void generateDay();
  void generateContextMenu();

  Q_SLOT void onContextMenuRequested(QPoint const& point);
  Q_SLOT void onCopyActionClicked(bool const checked);

  QPointer<QMenu> context_menu_;
  QPointer<QAction> copy_action_;
  QPointer<LabeledSpinBoxWidget> year_spinbox_;
  QPointer<LabeledSpinBoxWidget> month_spinbox_;
  QPointer<LabeledSpinBoxWidget> day_spinbox_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
