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

#include <QtCore/QPoint>
#include <QtCore/QPointer>
#include <QtWidgets/QAction>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QWidget>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
class InsertPageWidget;
template <typename Widget>
class MdiSubWindow;

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
  void generateMdiAreaMenu();
  void generateInsertPageAction();

  Q_SLOT void onContextMenuRequested(QPoint const& point);
  Q_SLOT void onInsertPageActionTriggered(bool const checked);

  QPointer<QMdiArea> central_widget_;
  QPointer<MdiSubWindow<InsertPageWidget>> insert_page_widget_;
  QPointer<QMenu> mdi_area_menu_;
  QPointer<QAction> insert_page_action_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
