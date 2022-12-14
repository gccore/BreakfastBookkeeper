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

#include <breakfast_bookkeeper/common_macros.hh>
//
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
//
#include <QtCore/QObject>
#include <QtCore/QPointer>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {

template <typename Widget>
class LabeledWidget final : public QWidget {
 public:
  using Layout = QHBoxLayout;

  explicit LabeledWidget(QWidget* const parent = nullptr) noexcept
      : QWidget(parent) {
    generateView();
  }

  QPointer<Widget> getWidget() const noexcept { return widget_; }
  QPointer<QLabel> getLabel() const noexcept { return label_; }

 private:
  QPointer<Layout> getLayout() const noexcept {
    QWIDGET_LAYOUT_IS_REQUIRED();
    return qobject_cast<Layout*>(this->QWidget::layout());
  }

  void generateView() {
    generateLayout();
    generateWidget();
  }
  void generateLayout() {
    QPointer<Layout> layout = new Layout;
    layout->setMargin(2);
    this->QWidget::setLayout(layout);
  }
  void generateWidget() {
    LAYOUT_IS_REQUIRED();

    label_ = new QLabel;
    widget_ = new Widget;
    getLayout()->addWidget(label_);
    getLayout()->addWidget(widget_);
  }

  QPointer<Widget> widget_;
  QPointer<QLabel> label_;
};

}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
