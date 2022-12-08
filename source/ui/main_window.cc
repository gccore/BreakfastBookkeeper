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

#include <breakfast_bookkeeper/constants.hh>
#include <breakfast_bookkeeper/ui/main_window.hh>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
MainWindow::MainWindow(QWidget* const parent) noexcept : QMainWindow(parent) {
  generateView();
}

QPointer<QHBoxLayout> MainWindow::getLayout() const {
  assert(this->QMainWindow::layout() && "Layout not found");
  return qobject_cast<QHBoxLayout*>(this->QMainWindow::layout());
}
void MainWindow::generateView() {
  generateLayout();
  generateMainWindowDefaults();
}
void MainWindow::generateLayout() {
  QPointer<QHBoxLayout> layout = new QHBoxLayout;

  layout->setMargin(constants::ui::kSomeDefaultMargin);

  this->QMainWindow::setLayout(layout);
}
void MainWindow::generateMainWindowDefaults() {
  this->QMainWindow::setWindowTitle(constants::names::kApplicationName);
  this->QMainWindow::setMinimumSize(constants::ui::kMinimumSize);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
