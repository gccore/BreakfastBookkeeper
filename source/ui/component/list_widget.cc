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
//
#include <QtWidgets/QFrame>
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

void ListWidget::addWidgetItem(QPointer<QWidget> const& widget_item) {
  REQUIRED(CONDITION qlist_widget_,
           ERROR_MESSAGE "The QListWidget doesn't exists");

  if (widget_item != nullptr) {
    QListWidgetItem* const item = new QListWidgetItem;
    item->setSizeHint(widget_item->sizeHint());
    qlist_widget_->addItem(item);
    qlist_widget_->setItemWidget(item, widget_item);
  }
}

QPointer<QHBoxLayout> ListWidget::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<QHBoxLayout*>(this->QWidget::layout());
}

void ListWidget::generateView() {
  generateLayout();
  generateQListWidget();
  generateSeperator();
  generateActionsLayout();
  generateTopActionsLayoutSpacer();
  generateAddAction();
  generateRemoveAction();
  generateBottomActionsLayoutSpacer();
}
void ListWidget::generateLayout() {
  QPointer<QHBoxLayout> layout = new QHBoxLayout;
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
void ListWidget::generateSeperator() {
  LAYOUT_IS_REQUIRED();

  QPointer<QFrame> horizontal_seperator = new QFrame;
  horizontal_seperator->setFrameShape(QFrame::HLine);
  horizontal_seperator->setLineWidth(2);
  getLayout()->addWidget(horizontal_seperator);
}
void ListWidget::generateActionsLayout() {
  LAYOUT_IS_REQUIRED();

  actions_layout_ = new QVBoxLayout;
  actions_layout_->setMargin(constants::ui::kSomeDefaultMargin);
  getLayout()->addLayout(actions_layout_);
}
void ListWidget::generateTopActionsLayoutSpacer() {
  REQUIRED(CONDITION actions_layout_,
           ERROR_MESSAGE "We don't have the actions layout");

  QSpacerItem* const spacer = new QSpacerItem(0, 1000);
  actions_layout_->addSpacerItem(spacer);
}
void ListWidget::generateAddAction() {
  REQUIRED(CONDITION actions_layout_,
           ERROR_MESSAGE "We don't have the actions layout");

  add_action_ = new QToolButton;
  add_action_->setText(QObject::tr("+"));
  actions_layout_->addWidget(add_action_);
  QObject::connect(add_action_, &QToolButton::clicked, this,
                   &ListWidget::onAddActionClicked);
}
void ListWidget::generateRemoveAction() {
  REQUIRED(CONDITION actions_layout_,
           ERROR_MESSAGE "We don't have the actions layout");

  remove_action_ = new QToolButton;
  remove_action_->setText(QObject::tr("-"));
  actions_layout_->addWidget(remove_action_);
  QObject::connect(remove_action_, &QToolButton::clicked, this,
                   &ListWidget::onRemoveActionClicked);
}
void ListWidget::generateBottomActionsLayoutSpacer() {
  REQUIRED(CONDITION actions_layout_,
           ERROR_MESSAGE "We don't have the actions layout");

  QSpacerItem* const spacer = new QSpacerItem(0, 1000);
  actions_layout_->addSpacerItem(spacer);
}

void ListWidget::onAddActionClicked(bool const checked) {
  Q_UNUSED(checked);
  Q_EMIT addActionClicked();
}
void ListWidget::onRemoveActionClicked(bool const checked) {
  Q_UNUSED(checked);
  Q_EMIT removeActionClicked();
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
