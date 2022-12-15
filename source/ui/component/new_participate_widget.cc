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
#include <QtWidgets/QSpacerItem>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {

NewParticipateWidget::NewParticipateWidget(QWidget* parent) noexcept
    : QWidget(parent), exit_code_(EXIT_FAILURE) {
  configure();
  generateView();
}

std::uint8_t NewParticipateWidget::getExitCode() const { return exit_code_; }

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
  generateApplyCancelButtons();
}
void NewParticipateWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  this->QWidget::setLayout(layout);
  this->QWidget::resize(QSize(600, 400));
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
void NewParticipateWidget::generateApplyCancelButtons() {
  LAYOUT_IS_REQUIRED();

  apply_button_ = new QPushButton(QObject::tr("Apply"));
  cancel_button_ = new QPushButton(QObject::tr("Cacnel"));

  QObject::connect(apply_button_, &QPushButton::clicked, this,
                   &NewParticipateWidget::onApplyClicked);
  QObject::connect(cancel_button_, &QPushButton::clicked, this,
                   &NewParticipateWidget::onCancelClicked);

  QHBoxLayout* const layout = new QHBoxLayout;
  QSpacerItem* const left_spacer = new QSpacerItem(100, 0);
  QSpacerItem* const right_spacer = new QSpacerItem(100, 0);

  layout->addSpacerItem(left_spacer);
  layout->addWidget(apply_button_);
  layout->addWidget(cancel_button_);
  layout->addSpacerItem(right_spacer);

  getLayout()->addLayout(layout);
}

void NewParticipateWidget::onOutlayListAddClicked() {
  REQUIRED(CONDITION outlay_list_,
           ERROR_MESSAGE "The outlay list object doesn't exist.");
  outlay_list_->addWidgetItem(new OutlayItemWidget);
}
void NewParticipateWidget::onOutlayListRemoveClicked(
    QPointer<ListWidgetItemContainer> const item) {
  REQUIRED(CONDITION outlay_list_,
           ERROR_MESSAGE "The outlay-list object doesn't exist.");
  REQUIRED(CONDITION outlay_list_->getQListWidget(),
           ERROR_MESSAGE "The outlay-list's internal object doesn't exists");
  REQUIRED(CONDITION item->getInternalWidget(),
           ERROR_MESSAGE "The remove reqested item doesn't have a widget");

  QListWidget* const qlist_widget = outlay_list_->getQListWidget();
  QListWidgetItem* const corresponding_item = item->getCorrespondingItem();

  qlist_widget->removeItemWidget(corresponding_item);
  delete qlist_widget->takeItem(qlist_widget->row(corresponding_item));
  item->getInternalWidget()->deleteLater();
}
void NewParticipateWidget::onApplyClicked() {
  exit_code_ = EXIT_SUCCESS;
  this->QWidget::close();
}
void NewParticipateWidget::onCancelClicked() {
  exit_code_ = EXIT_FAILURE;
  this->QWidget::close();
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
