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

#include <breakfast_bookkeeper/ui/component/list_widget_add_item_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
ListWidgetAddItemWidget::ListWidgetAddItemWidget(QWidget* const parent) noexcept
    : QWidget(parent) {
  generateView();
}

QPointer<ListWidgetAddItemWidget::Layout> ListWidgetAddItemWidget::getLayout()
    const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void ListWidgetAddItemWidget::generateView() {
  generateLayout();
  generateAddButton();
}
void ListWidgetAddItemWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  this->QWidget::setLayout(layout);
}
void ListWidgetAddItemWidget::generateAddButton() {
  LAYOUT_IS_REQUIRED();

  add_button_ = new QPushButton(QObject::tr("+"));
  getLayout()->addWidget(add_button_);
  QObject::connect(add_button_, &QPushButton::clicked, this,
                   &ListWidgetAddItemWidget::clicked);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
