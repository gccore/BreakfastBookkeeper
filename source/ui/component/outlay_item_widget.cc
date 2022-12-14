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

#include <breakfast_bookkeeper/ui/component/outlay_item_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/ui/component/labeled_widget.hh>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
OutlayItemWidget::OutlayItemWidget(QWidget* const parent) noexcept
    : QWidget(parent) {
  generateView();
}

void OutlayItemWidget::setCost(std::int32_t const cost) {
  REQUIRED(CONDITION cost_,
           ERROR_MESSAGE "The cost object somehow doesn't exists");
  cost_->getWidget()->setValue(cost);
}
std::int32_t OutlayItemWidget::getCost() const {
  REQUIRED(CONDITION cost_,
           ERROR_MESSAGE "The cost object somehow doesn't exists");
  return cost_->getWidget()->value();
}

void OutlayItemWidget::setDescription(QString const& description) {
  REQUIRED(CONDITION description_,
           ERROR_MESSAGE "The description object doesn't exists");
  description_->getWidget()->setText(description);
}
QString OutlayItemWidget::getDescription() const {
  REQUIRED(CONDITION description_,
           ERROR_MESSAGE "The description object doesn't exists");
  return description_->getWidget()->text();
}

QPointer<OutlayItemWidget::Layout> OutlayItemWidget::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void OutlayItemWidget::generateView() {
  generateLayout();
  generateDescription();
  generateCost();
}
void OutlayItemWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  layout->setMargin(2);
  this->QWidget::setLayout(layout);
}
void OutlayItemWidget::generateCost() {
  LAYOUT_IS_REQUIRED();

  cost_ = new LabeledWidget<QSpinBox>;
  cost_->getLabel()->setText(QObject::tr("Cost: "));
  getLayout()->addWidget(cost_);
}
void OutlayItemWidget::generateDescription() {
  LAYOUT_IS_REQUIRED();

  description_ = new LabeledWidget<QLineEdit>;
  description_->getLabel()->setText(QObject::tr("Description: "));
  getLayout()->addWidget(description_);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
