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
#include <QtCore/QPointer>
#include <QtWidgets/QMdiSubWindow>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
template <typename Widget>
class MdiSubWindow final : public QMdiSubWindow {
 public:
  explicit MdiSubWindow() : widget_(new Widget) {
    this->QMdiSubWindow::setWidget(widget_);
  }

  QPointer<Widget> getWidget() const { return widget_; }

  void setDeleteOnClose(bool state = true) {
    this->QMdiSubWindow::setAttribute(Qt::WA_DeleteOnClose, state);
  }

  void showNormal() {
    REQUIRED(CONDITION widget_,
             ERROR_MESSAGE "The widget object doesn't exists");

    this->QMdiSubWindow::showNormal();
    widget_->setVisible(true);
  }

 private:
  QPointer<Widget> widget_;
  QPointer<QMdiSubWindow> sub_window_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
