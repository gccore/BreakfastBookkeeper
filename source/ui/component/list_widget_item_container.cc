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

#include <breakfast_bookkeeper/ui/component/list_widget_item_container.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/utilities.hh>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {

ListWidgetItemContainer::ListWidgetItemContainer(QWidget* const parent) noexcept
    : QWidget(parent) {
  generateView();
}

void ListWidgetItemContainer::setInternalWidget(
    QWidget* const internal_widget) {
  LAYOUT_IS_REQUIRED();

  internal_widget_ = internal_widget;
  getLayout()->addWidget(internal_widget_, utilities::Row(0),
                         utilities::Column(0));
}
QPointer<QWidget> ListWidgetItemContainer::getInternalWidget() const {
  return internal_widget_;
}

void ListWidgetItemContainer::setCorrespondingItem(
    QListWidgetItem* const item) {
  corresponding_item_ = item;
}
QListWidgetItem* ListWidgetItemContainer::getCorrespondingItem() const {
  return corresponding_item_;
}

QPointer<QGridLayout> ListWidgetItemContainer::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<QGridLayout*>(this->QWidget::layout());
}

void ListWidgetItemContainer::generateView() {
  generateLayout();
  generateRemoveButton();
}
void ListWidgetItemContainer::generateLayout() {
  QPointer<QGridLayout> layout = new QGridLayout;

  layout->setMargin(0);
  this->QWidget::setLayout(layout);
}
void ListWidgetItemContainer::generateRemoveButton() {
  LAYOUT_IS_REQUIRED();

  remove_button_ = new QToolButton;
  remove_button_->setText("X");
  remove_button_->setStyleSheet("color: red");
  QObject::connect(remove_button_, &QToolButton::clicked, this,
                   &ListWidgetItemContainer::onRemoveClicked);

  getLayout()->addWidget(remove_button_, utilities::Row(0),
                         utilities::Column(1), Qt::AlignRight);
}

void ListWidgetItemContainer::onRemoveClicked() { Q_EMIT removeClicked(this); }
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
