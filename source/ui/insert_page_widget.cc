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

#include <breakfast_bookkeeper/ui/insert_page_widget.hh>
//
#include <breakfast_bookkeeper/common_macros.hh>
#include <breakfast_bookkeeper/constants.hh>
#include <breakfast_bookkeeper/ui/component/list_widget.hh>
#include <breakfast_bookkeeper/ui/component/new_participate_widget.hh>
#include <breakfast_bookkeeper/ui/component/raw_date_widget.hh>
//
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpacerItem>
//
#include <cassert>

namespace gccore {
namespace breakfast_bookkeeper {
namespace ui {
InsertPageWidget::InsertPageWidget(QWidget* const parent) noexcept
    : QWidget(parent) {
  generateView();
}

QPointer<InsertPageWidget::Layout> InsertPageWidget::getLayout() const {
  QWIDGET_LAYOUT_IS_REQUIRED();
  return qobject_cast<Layout*>(this->QWidget::layout());
}

void InsertPageWidget::generateView() {
  generateLayout();
  generateCurrentDay();
  generateParticipantList();
}
void InsertPageWidget::generateLayout() {
  QPointer<Layout> layout = new Layout;
  layout->setMargin(constants::ui::kSomeDefaultMargin);
  this->QWidget::setLayout(layout);
}
void InsertPageWidget::generateCurrentDay() {
  LAYOUT_IS_REQUIRED();

  current_day_ = new RawDateWidget;
  current_day_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  QHBoxLayout* const layout = new QHBoxLayout;
  layout->addSpacerItem(new QSpacerItem(100, 0));
  layout->addWidget(current_day_);
  layout->addSpacerItem(new QSpacerItem(100, 0));

  getLayout()->addLayout(layout, Qt::AlignCenter);
}
void InsertPageWidget::generateParticipantList() {
  LAYOUT_IS_REQUIRED();

  participant_list_ = new ListWidget;
  participant_list_->getQListWidget()->setSpacing(5);
  participant_list_->getQListWidget()->setSelectionRectVisible(false);
  participant_list_->getQListWidget()->setSelectionMode(
      QListWidget::NoSelection);
  getLayout()->addWidget(participant_list_);

  QObject::connect(participant_list_, &ListWidget::addActionClicked, this, [] {
    NewParticipateWidget* const new_participate = new NewParticipateWidget;
    new_participate->setWindowModality(Qt::ApplicationModal);
    new_participate->show();
  });
}
}  // namespace ui
}  // namespace breakfast_bookkeeper
}  // namespace gccore
