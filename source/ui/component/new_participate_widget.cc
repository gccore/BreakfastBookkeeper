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

#include <breakfast_bookkeeper/ui/component/new_participate_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/ui/component/labeled_widget.hh>
#include <breakfast_bookkeeper/ui/component/list_widget.hh>
#include <breakfast_bookkeeper/ui/component/list_widget_item_container.hh>
#include <breakfast_bookkeeper/ui/component/outlay_item_widget.hh>
//
#include <QtWidgets/QGroupBox>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {

NewParticipateWidget::NewParticipateWidget(QWidget* parent) noexcept
    : QWidget(parent) {
  configure();
  generateView();
}

QPointer<NewParticipateWidget::Layout> NewParticipateWidget::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void NewParticipateWidget::configure() { configureQWidget(); }
void NewParticipateWidget::configureQWidget() {
  this->QWidget::setWindowTitle(QObject::tr("New Participate"));
}

void NewParticipateWidget::generateView() {
  generateLayout();
  generateParticipateName();
  generateOutlayList();
}
void NewParticipateWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  this->QWidget::setLayout(layout);
  this->QWidget::resize(QSize(500, 300));
}
void NewParticipateWidget::generateParticipateName() {
  LAYOUT_IS_REQUIRED();

  participate_name_ = new LabeledWidget<QLineEdit>();
  participate_name_->getLabel()->setText(QObject::tr("Name: "));
  getLayout()->addWidget(participate_name_);
}
void NewParticipateWidget::generateOutlayList() {
  LAYOUT_IS_REQUIRED();

  outlay_list_ = new ListWidget;
  outlay_list_->getQListWidget()->setSpacing(5);
  outlay_list_->getQListWidget()->setSelectionRectVisible(false);
  outlay_list_->getQListWidget()->setSelectionMode(QListWidget::NoSelection);

  QObject::connect(outlay_list_, &ListWidget::addActionClicked, this,
                   &NewParticipateWidget::onOutlayListAddClicked);
  QObject::connect(outlay_list_, &ListWidget::removeActionClicked, this,
                   &NewParticipateWidget::onOutlayListRemoveClicked);

  QGroupBox* const groupbox = new QGroupBox;
  groupbox->setTitle(QObject::tr("Outlays:"));

  QHBoxLayout* const groupbox_layout = new QHBoxLayout;
  groupbox->setLayout(groupbox_layout);
  groupbox_layout->addWidget(outlay_list_);
  groupbox_layout->setMargin(2);

  getLayout()->addWidget(groupbox);
}

void NewParticipateWidget::onOutlayListAddClicked() {
  REQUIRED(CONDITION outlay_list_,
           ERROR_MESSAGE "The outlay list object doesn't exist.");
  outlay_list_->addWidgetItem(new OutlayItemWidget);
}
void NewParticipateWidget::onOutlayListRemoveClicked(
    QPointer<ListWidgetItemContainer> const item) {
  REQUIRED(CONDITION outlay_list_,
           ERROR_MESSAGE "The outlay list object doesn't exist.");
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
