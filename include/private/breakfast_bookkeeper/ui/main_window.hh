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

#include <QtCore/QPointer>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QWidget>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class InsertPageWidget;

class MainWindow final : public QMainWindow {
  Q_OBJECT

  using Layout = QHBoxLayout;

 public:
  explicit MainWindow(QWidget* const parent = nullptr) noexcept;

 private:
  void configureApplication();
  void configureQApplication();

  void generateView();
  void generateCentralWidget();
  void generateMainWindowDefaults();
  void generateInsertPageWidget();

  QPointer<QMdiArea> central_widget_;
  QPointer<InsertPageWidget> insert_page_widget_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
