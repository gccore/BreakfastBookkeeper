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

#include <breakfast_bookkeeper/ui/main_window.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/constants.hh>
#include <breakfast_bookkeeper/ui/insert_page_widget.hh>
//
#include <QtWidgets/QApplication>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
MainWindow::MainWindow(QWidget* const parent) noexcept : QMainWindow(parent) {
  configureApplication();
  generateView();
}

QPointer<QHBoxLayout> MainWindow::getLayout() const {
  REQUIRED(CONDITION central_widget_,
           ERROR_MESSAGE "Centeral widget dosn't exists");
  REQUIRED(CONDITION central_widget_->layout(),
           ERROR_MESSAGE "The central widget doesn't have any layout");
  return qobject_cast<QHBoxLayout*>(central_widget_->layout());
}

void MainWindow::configureApplication() { configureQApplication(); }
void MainWindow::configureQApplication() {
  qApp->setApplicationName(constants::names::kApplicationName);
  qApp->setApplicationVersion(constants::names::kApplicationVersion);
  qApp->setOrganizationName(constants::names::kApplicationOrganization);
}

void MainWindow::generateView() {
  generateCentralWidget();
  generateLayout();
  generateMainWindowDefaults();
  generateInsertPageWidget();
}
void MainWindow::generateCentralWidget() {
  central_widget_ = new QWidget;
  this->QMainWindow::setCentralWidget(central_widget_);
}
void MainWindow::generateLayout() {
  REQUIRED(CONDITION central_widget_,
           ERROR_MESSAGE "We don't have any central widget");

  QPointer<QHBoxLayout> layout = new QHBoxLayout;

  layout->setMargin(constants::ui::kSomeDefaultMargin);
  central_widget_->setLayout(layout);
}
void MainWindow::generateMainWindowDefaults() {
  this->QMainWindow::setWindowTitle(constants::names::kApplicationName);
  this->QMainWindow::setMinimumSize(constants::ui::kMinimumSize);
}
void MainWindow::generateInsertPageWidget() {
  LAYOUT_IS_REQUIRED();

  insert_page_widget_ = new InsertPageWidget;
  getLayout()->addWidget(insert_page_widget_);
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
