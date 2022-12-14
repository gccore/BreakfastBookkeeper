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
#include <QtWidgets/QWidget>
//
#include <QtCore/QPointer>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class ListWidgetItemContainer;

class ListWidget final : public QWidget {
  Q_OBJECT

  using Layout = QHBoxLayout;

 public:
  enum class PositionKinds { First, Last };

  explicit ListWidget(QWidget* const parent = nullptr) noexcept;

  QPointer<QListWidget> getQListWidget() const;

  void addWidgetItem(QWidget* const widget_item, std::int32_t const item_row);
  void addWidgetItem(QWidget* const widget_item,
                     PositionKinds const position = PositionKinds::Last);

  Q_SIGNAL void addActionClicked();
  Q_SIGNAL void removeActionClicked(
      QPointer<ListWidgetItemContainer> const item);

 private:
  QPointer<Layout> getLayout() const;

  void generateView();
  void generateLayout();
  void generateQListWidget();
  void generateAddItem();

  std::int32_t normalizeRowIndex(std::int32_t const item_row) const noexcept;

  QPointer<QListWidget> qlist_widget_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
