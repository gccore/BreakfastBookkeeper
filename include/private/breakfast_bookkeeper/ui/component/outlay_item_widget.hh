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
#include <QtCore/QString>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
//
#include <cstdint>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
template <typename Widget>
class LabeledWidget;

class OutlayItemWidget final : public QWidget {
  Q_OBJECT

  using Layout = QHBoxLayout;

 public:
  explicit OutlayItemWidget(QWidget* const parent = nullptr) noexcept;

  void setCost(std::int32_t const cost);
  std::int32_t getCost() const;

  void setDescription(QString const& description);
  QString getDescription() const;

 private:
  QPointer<Layout> getLayout() const;

  void generateView();
  void generateLayout();
  void generateCost();
  void generateDescription();

  QPointer<LabeledWidget<QSpinBox>> cost_;
  QPointer<LabeledWidget<QLineEdit>> description_;
};
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
