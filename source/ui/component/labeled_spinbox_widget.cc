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

#include <breakfast_bookkeeper/ui/component/labeled_spinbox_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/constants.hh>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
LabeledSpinBoxWidget::LabeledSpinBoxWidget(QWidget *const parent) noexcept
    : QWidget(parent) {
  generateView();
}

QPointer<QSpinBox> LabeledSpinBoxWidget::getSpinBox() const noexcept {
  return spin_box_;
}
QPointer<QLabel> LabeledSpinBoxWidget::getLabel() const noexcept {
  return label_;
}

QPointer<QHBoxLayout> LabeledSpinBoxWidget::getLayout() const noexcept {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<QHBoxLayout *>(this->QWidget::layout());
}

void LabeledSpinBoxWidget::generateView() {
  generateLayout();
  generateSpinBox();
}
void LabeledSpinBoxWidget::generateLayout() {
  QPointer<QHBoxLayout> layout = new QHBoxLayout;

  layout->setMargin(constants::ui::kSomeDefaultMargin);

  this->QWidget::setLayout(layout);
}
void LabeledSpinBoxWidget::generateSpinBox() {
  LAYOUT_IS_REQUIRED();

  label_ = new QLabel;
  spin_box_ = new QSpinBox;
  getLayout()->addWidget(label_);
  getLayout()->addWidget(spin_box_);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
