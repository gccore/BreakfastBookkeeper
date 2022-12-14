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

#include <breakfast_bookkeeper/ui/component/list_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/constants.hh>
#include <breakfast_bookkeeper/ui/component/list_widget_add_item_widget.hh>
#include <breakfast_bookkeeper/ui/component/list_widget_item_container.hh>
//
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
ListWidget::ListWidget(QWidget* const parent) noexcept : QWidget(parent) {
  generateView();
}

QPointer<QListWidget> ListWidget::getQListWidget() const {
  return qlist_widget_;
}

void ListWidget::addWidgetItem(QWidget* const widget_item,
                               std::int32_t const item_row) {
  REQUIRED(CONDITION qlist_widget_,
           ERROR_MESSAGE "The QListWidget doesn't exists");

  if (widget_item != nullptr) {
    QPointer<ListWidgetItemContainer> const item_container =
        new ListWidgetItemContainer;
    item_container->setInternalWidget(widget_item);
    QObject::connect(item_container, &ListWidgetItemContainer::removeClicked,
                     this, &ListWidget::removeActionClicked);

    QListWidgetItem* const item = new QListWidgetItem;
    item->setSizeHint(item_container->sizeHint());
    item_container->setCorrespondingItem(item);

    qlist_widget_->insertItem(normalizeRowIndex(item_row), item);
    qlist_widget_->setItemWidget(item, item_container);
  }
}
void ListWidget::addWidgetItem(QWidget* const widget_item,
                               PositionKinds const position) {
  REQUIRED(CONDITION qlist_widget_,
           ERROR_MESSAGE "The QListWidget doesn't exists");

  if (widget_item != nullptr) {
    addWidgetItem(widget_item, PositionKinds::First == position
                                   ? 1
                                   : qlist_widget_->count());
  }
}

QPointer<ListWidget::Layout> ListWidget::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void ListWidget::generateView() {
  generateLayout();
  generateQListWidget();
  generateAddItem();
}
void ListWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  layout->setMargin(constants::ui::kSomeDefaultMargin);
  this->QWidget::setLayout(layout);
}
void ListWidget::generateQListWidget() {
  LAYOUT_IS_REQUIRED();

  qlist_widget_ = new QListWidget;
  qlist_widget_->setHorizontalScrollMode(QListWidget::ScrollPerPixel);
  qlist_widget_->setVerticalScrollMode(QListWidget::ScrollPerPixel);
  getLayout()->addWidget(qlist_widget_);
}
void ListWidget::generateAddItem() {
  REQUIRED(CONDITION qlist_widget_,
           ERROR_MESSAGE "The QListWidget object doesn't exists.");

  QPointer<ListWidgetAddItemWidget> add_button = new ListWidgetAddItemWidget;
  QObject::connect(add_button, &ListWidgetAddItemWidget::clicked, this,
                   &ListWidget::addActionClicked);
  QListWidgetItem* const item = new QListWidgetItem;
  item->setSizeHint(add_button->sizeHint());
  qlist_widget_->addItem(item);
  qlist_widget_->setItemWidget(item, add_button);
}

std::int32_t ListWidget::normalizeRowIndex(
    std::int32_t const row_index) const noexcept {
  return row_index == 0 ? 1 : row_index;
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
