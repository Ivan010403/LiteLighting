#include "groupbutton.h"

GroupButton::GroupButton(Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, int number, const int* ptr, QWidget* parent) :
    selected_fixture_(selected_fixture),
    dmx_fixture_array_(dmx_fixture_array),
    number_(number),
    ptr_current_amount_(ptr),
    QPushButton(parent)
{
    SetupUi();
    SetupConnections();
}

GroupButton::~GroupButton() {
    delete group_; // опасно!
}

void GroupButton::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawBorder(painter);
    drawText(painter);
}

void GroupButton::mousePressEvent(QMouseEvent* event) {
    if ((event->button() == Qt::RightButton) && (!group_)) {
        qdial_grouping_->exec();
    } else if ((event->button() == Qt::RightButton) && (group_)) {
        qdial_editor_->exec();
    } else {
        QPushButton::mousePressEvent(event);
    }
}

void GroupButton::mouseDoubleClickEvent(QMouseEvent* event) {
    if ((event->button() == Qt::LeftButton) && (group_)) {
        (*selected_fixture_) = group_;
        emit Mediator::instance().SelectingFixture();
        emit Mediator::instance().SelectingCommand();
        qDebug() << "GroupButton::mouseDoubleClickEvent() --> выбор группы как selected_fixture";

        QPushButton::mouseDoubleClickEvent(event);
    } else {
        QPushButton::mouseDoubleClickEvent(event);
    }
}

void GroupButton::OnDeleteFixture(Fixture* fxtr) {
    if (group_) {
        group_->DeleteFixture(fxtr);
    }
}

void GroupButton::onDeleteCurrent() {
    delete group_;
    group_ = nullptr;
    setText("");
}

void GroupButton::OnGroupCreatedMediator(int group_id, Fixture* fxtr, const QString& group_name) {
    if ((group_id == -1) && (group_)) {
        delete group_;
        group_ = nullptr;
        qDebug() << "OnGroupCreatedMediator() --> удаление уже существующей группы";
        return;
    }

    if (number_ == group_id) {
        if (*ptr_current_amount_ <= number_ + 1) emit onEndedButtons();

        if (group_) {
            group_->AddFixture(fxtr);
            qDebug() << "OnGroupCreatedMediator() --> добавление фикстуры в группу с group id " << group_id << " fix id = " << fxtr->GetFixtureId();
        }
        else {
            group_ = new FixtureGroup(group_id, group_name);
            dmx_fixture_array_->AddFixtureToMap(group_);
            qDebug() << "OnGroupCreatedMediator() --> добавление фикстуры в группу с group id " << group_id << " fix id = " << fxtr->GetFixtureId();
            group_->AddFixture(fxtr);
            setText(group_name);
        }
    }
}

void GroupButton::OnGroupCreated(const QModelIndexList& selected_indexes, const QString& name) {
    QSet<int> unique_rows;
    for (const QModelIndex& index : selected_indexes) {
        if (index.isValid()) {
            unique_rows.insert(index.row());
        }
    }

    std::vector<Fixture*> vect_fxtr;

    for (const int var : unique_rows) {
        if (dmx_fixture_array_->GetFixtureByIndex(var)->group_id_ == 0) {
            vect_fxtr.push_back(dmx_fixture_array_->GetFixtureByIndex(var));
        }
    }

    if (vect_fxtr.size() > 1) {
        group_ = new FixtureGroup(number_, vect_fxtr, name);
        dmx_fixture_array_->AddFixtureToMap(group_);

        qDebug() << "GroupButton::OnGroupCreated() --> создание группы";

        setText(name);

        if (*ptr_current_amount_ == number_ + 1) emit onEndedButtons();
    }
}

void GroupButton::SetupUi() {
    setFixedSize(60, 60);

    qdial_grouping_ = new QDialogGrouping(dmx_fixture_array_, this);
    qdial_editor_ = new QDialogEditor(this);
}

void GroupButton::SetupConnections() {
    connect(qdial_grouping_, &QDialogGrouping::GroupCreating, this, &GroupButton::OnGroupCreated);

    connect(&Mediator::instance(), &Mediator::CreationGroup, this, &GroupButton::OnGroupCreatedMediator);
    connect(&Mediator::instance(), &Mediator::DeletingFixture, this, &GroupButton::OnDeleteFixture);

    connect(qdial_editor_, &QDialogEditor::onDeleteClicked, this, &GroupButton::onDeleteCurrent);
}

void GroupButton::drawBackground(QPainter& painter) {
    QBrush brush (QColor(29, 33, 34));

    if (isDown()) {
        brush.setColor(QColor(59, 63, 64));
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 10, 10);
}

void GroupButton::drawBorder(QPainter& painter) {
    QPen pen(QColor(96, 102, 104));

    if (isDown()) {
        pen.setColor(QColor(118, 156, 227));
    }

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 10, 10);
}

void GroupButton::drawText(QPainter& painter) {
    QFont new_font = font();
    new_font.setPointSize(8);

    painter.setPen(Qt::white);
    painter.setFont(new_font);

    painter.drawText(rect().adjusted(0, 10, 0, 0), Qt::AlignTop | Qt::AlignHCenter, QString::number(number_));
    painter.drawText(rect().adjusted(0, 20, 0, 0), Qt::TextWordWrap | Qt::AlignCenter, text());
}
