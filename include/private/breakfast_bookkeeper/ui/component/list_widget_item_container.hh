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
#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class ListWidgetItemContainer final : public QWidget {
  Q_OBJECT

 public:
  explicit ListWidgetItemContainer(QWidget* parent = nullptr) noexcept;

  void setInternalWidget(QWidget* const internal_widget);
  QPointer<QWidget> getInternalWidget() const;

  void setCorrespondingItem(QListWidgetItem* const item);
  QListWidgetItem* getCorrespondingItem() const;

  Q_SIGNAL void removeClicked(QPointer<ListWidgetItemContainer> const item);

 private:
  QPointer<QGridLayout> getLayout() const;

  void generateView();
  void generateLayout();
  void generateRemoveButton();

  Q_SLOT void onRemoveClicked();

  QPointer<QToolButton> remove_button_;
  QPointer<QWidget> internal_widget_;
  QListWidgetItem* corresponding_item_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
