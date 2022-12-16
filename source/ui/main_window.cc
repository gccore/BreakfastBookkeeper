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
#include <breakfast_bookkeeper/ui/component/mdi_sub_window.hh>
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

void MainWindow::configureApplication() { configureQApplication(); }
void MainWindow::configureQApplication() {
  qApp->setApplicationName(constants::names::kApplicationName);
  qApp->setApplicationVersion(constants::names::kApplicationVersion);
  qApp->setOrganizationName(constants::names::kApplicationOrganization);
}

void MainWindow::generateView() {
  generateCentralWidget();
  generateMainWindowDefaults();
  generateInsertPageWidget();
  generateMdiAreaMenu();
  generateInsertPageAction();
}
void MainWindow::generateCentralWidget() {
  central_widget_ = new QMdiArea;
  this->QMainWindow::setCentralWidget(central_widget_);
}
void MainWindow::generateMainWindowDefaults() {
  this->QMainWindow::setWindowTitle(constants::names::kApplicationName);
  this->QMainWindow::setMinimumSize(constants::ui::kMinimumSize);
}
void MainWindow::generateInsertPageWidget() {
  insert_page_widget_ = new MdiSubWindow<InsertPageWidget>;
}
void MainWindow::generateMdiAreaMenu() {
  REQUIRED(CONDITION central_widget_,
           ERROR_MESSAGE "The centeral widget object doesn't exists");

  mdi_area_menu_ = new QMenu;
  central_widget_->setContextMenuPolicy(Qt::CustomContextMenu);

  QObject::connect(central_widget_, &QMdiArea::customContextMenuRequested, this,
                   &MainWindow::onContextMenuRequested);
}
void MainWindow::generateInsertPageAction() {
  REQUIRED(CONDITION mdi_area_menu_,
           ERROR_MESSAGE "The QMenu object doesn't exists");

  QAction* const action = new QAction(QObject::tr("Insert Page"), nullptr);
  QObject::connect(action, &QAction::triggered, this,
                   &MainWindow::onInsertPageActionTriggered);

  mdi_area_menu_->addAction(action);
}

void MainWindow::onContextMenuRequested(QPoint const& point) {
  REQUIRED(CONDITION mdi_area_menu_,
           ERROR_MESSAGE "The QMenu object doesn't exists");

  mdi_area_menu_->popup(this->QMainWindow::mapToGlobal(point));
}
void MainWindow::onInsertPageActionTriggered(bool const checked) {
  Q_UNUSED(checked);

  REQUIRED(CONDITION insert_page_widget_,
           ERROR_MESSAGE "The InsertPageWidget object doesn't exists");
  REQUIRED(CONDITION central_widget_,
           ERROR_MESSAGE "The central widget doesn't exists");

  if (central_widget_->subWindowList().indexOf(insert_page_widget_) == -1) {
    central_widget_->addSubWindow(insert_page_widget_)->showNormal();
  } else {
    insert_page_widget_->showNormal();
  }
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
