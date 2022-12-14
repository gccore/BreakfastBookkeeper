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

#include <breakfast_bookkeeper/ui/component/raw_date_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/constants.hh>
#include <breakfast_bookkeeper/ui/component/labeled_widget.hh>
//
#include <QtGui/QCursor>
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
RawDateWidget::RawDateWidget(QWidget* const parent) noexcept : QWidget(parent) {
  generateView();
}

QPointer<RawDateWidget::Layout> RawDateWidget::getLayout() const noexcept {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void RawDateWidget::addAdditionalSpacer() {
  LAYOUT_IS_REQUIRED();
  getLayout()->addSpacerItem(new QSpacerItem(1000, 0));
}

void RawDateWidget::generateView() {
  generateLayout();
  addAdditionalSpacer();
  generateYear();
  generateMonth();
  generateDay();
  addAdditionalSpacer();
  generateContextMenu();
}
void RawDateWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;

  layout->setMargin(constants::ui::kSomeDefaultMargin);

  this->QWidget::setLayout(layout);
}
void RawDateWidget::generateYear() {
  LAYOUT_IS_REQUIRED();

  year_spinbox_ = new LabeledWidget<QSpinBox>;
  year_spinbox_->getWidget()->setRange(constants::ui::kMinimumYear,
                                       constants::ui::kMaximumYear);
  year_spinbox_->getLabel()->setText(constants::names::kYearLabel);

  getLayout()->addWidget(year_spinbox_);
}
void RawDateWidget::generateMonth() {
  LAYOUT_IS_REQUIRED();

  month_spinbox_ = new LabeledWidget<QSpinBox>;
  month_spinbox_->getWidget()->setRange(constants::ui::kMinimumMonth,
                                        constants::ui::kMaximumMonth);
  month_spinbox_->getLabel()->setText(constants::names::kMonthLabel);

  getLayout()->addWidget(month_spinbox_);
}
void RawDateWidget::generateDay() {
  LAYOUT_IS_REQUIRED();

  day_spinbox_ = new LabeledWidget<QSpinBox>;
  day_spinbox_->getWidget()->setRange(constants::ui::kMinimumDay,
                                      constants::ui::kMaximumDay);
  day_spinbox_->getLabel()->setText(constants::names::kDayLabel);

  getLayout()->addWidget(day_spinbox_);
}
void RawDateWidget::generateContextMenu() {
  context_menu_ = new QMenu;
  copy_action_ = new QAction(constants::names::kCopyAction, nullptr);

  context_menu_->addAction(copy_action_);
  QObject::connect(copy_action_, &QAction::triggered, this,
                   &RawDateWidget::onCopyActionClicked);

  this->QWidget::setContextMenuPolicy(Qt::CustomContextMenu);
  QObject::connect(this, &QWidget::customContextMenuRequested, this,
                   &RawDateWidget::onContextMenuRequested);
}

void RawDateWidget::onContextMenuRequested(QPoint const& point) {
  REQUIRED(CONDITION context_menu_,
           ERROR_MESSAGE "We don't have any initialized QMenu");

  context_menu_->popup(this->QWidget::mapToGlobal(point));
}
void RawDateWidget::onCopyActionClicked(bool const checked) {
  Q_UNUSED(checked);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
