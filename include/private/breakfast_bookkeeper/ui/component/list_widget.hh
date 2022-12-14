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

#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
//
#include <QtCore/QPointer>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class ListWidget final : public QWidget {
  Q_OBJECT

 public:
  explicit ListWidget(QWidget* const parent = nullptr) noexcept;

  QPointer<QListWidget> getQListWidget() const;

  void addWidgetItem(QPointer<QWidget> const& widget_item);

  Q_SIGNAL void addActionClicked();
  Q_SIGNAL void removeActionClicked();
  Q_SIGNAL void itemAdded(QPointer<QListWidgetItem> const& new_item);
  Q_SIGNAL void itemRemoved();

 private:
  QPointer<QHBoxLayout> getLayout() const;

  void generateView();
  void generateLayout();
  void generateQListWidget();
  void generateSeperator();
  void generateActionsLayout();
  void generateTopActionsLayoutSpacer();
  void generateAddAction();
  void generateRemoveAction();
  void generateBottomActionsLayoutSpacer();

  Q_SLOT void onAddActionClicked(bool const checked);
  Q_SLOT void onRemoveActionClicked(bool const checkedS);

  QPointer<QListWidget> qlist_widget_;
  QPointer<QVBoxLayout> actions_layout_;
  QPointer<QToolButton> add_action_;
  QPointer<QToolButton> remove_action_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
