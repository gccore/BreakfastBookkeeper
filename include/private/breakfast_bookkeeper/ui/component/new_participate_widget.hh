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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
//
#include <cstdint>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
template <typename Widget>
class LabeledWidget;
class ListWidget;
class ListWidgetItemContainer;

class NewParticipateWidget final : public QWidget {
  Q_OBJECT

  using Layout = QVBoxLayout;

 public:
  explicit NewParticipateWidget(QWidget* parent = nullptr) noexcept;

  std::uint8_t getExitCode() const;

 private:
  QPointer<Layout> getLayout() const;

  void configure();
  void configureQWidget();

  void generateView();
  void generateLayout();
  void generateParticipateName();
  void generateOutlayList();
  void generateApplyCancelButtons();

  Q_SLOT void onOutlayListAddClicked();
  Q_SLOT void onOutlayListRemoveClicked(
      QPointer<ListWidgetItemContainer> const item);
  Q_SLOT void onApplyClicked();
  Q_SLOT void onCancelClicked();

  QPointer<LabeledWidget<QLineEdit>> participate_name_;
  QPointer<ListWidget> outlay_list_;
  QPointer<QPushButton> apply_button_;
  QPointer<QPushButton> cancel_button_;
  std::uint8_t exit_code_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
