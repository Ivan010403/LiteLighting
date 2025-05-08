#include "programmingbutton.h"

ProgrammingButton::ProgrammingButton(AbstractCommand** main_command, ProgrammingType type_channels, int number, QWidget* parent) :
    main_command_(main_command),
    type_channels_(type_channels),
    number_(number),
    QPushButton(parent)
{
    SetupUi();
    SetupConnections();
}

ProgrammingButton::~ProgrammingButton() {
    delete current_command_;
}

void ProgrammingButton::SetCommand(AbstractCommand* command) {
    current_command_ = command; // а если уже была команда?!!!!!!
    setText(current_command_->name_);
    qDebug() << "ProgrammingButton::SetCommand() --> команда установлена в " << ProgrammingTypeToQString(type_channels_) << number_;
}

void ProgrammingButton::DeleteCurrentCommand() {
    current_command_ = nullptr;

    qDebug() << "ProgrammingButton::DeleteCurrentCommand() --> команда удалена (если она была)" << ProgrammingTypeToQString(type_channels_) << number_;
}

void ProgrammingButton::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawBorder(painter);
    drawText(painter);
}

void ProgrammingButton::mousePressEvent(QMouseEvent* event) {
    if ((event->button() == Qt::RightButton) && (!current_command_) && ((*main_command_)->Size() != 0)) {
        qdial_save_command_->exec();
    } else {
        QPushButton::mousePressEvent(event);
    }
}

void ProgrammingButton::mouseDoubleClickEvent(QMouseEvent* event) {
    if ((event->button() == Qt::LeftButton) && (current_command_)) {
        current_command_->Execute();
    } else {
        QPushButton::mouseDoubleClickEvent(event);
    }
}

void ProgrammingButton::onSaveClicked(const QString& name) {
    current_command_ = *main_command_;
    bool result = current_command_->SetData(type_channels_, number_, name);

    qDebug() << "ProgrammingButton::onSaveClicked() --> попытка сохранения command";

    if (result) {
        CommandArray::instance().AddCommand(current_command_);

        *main_command_ = new AbstractCommand();
        setText(name);

        qDebug() << "ProgrammingButton::onSaveClicked() --> командна сохранена успешно";
    }
    else {
        delete current_command_;
        current_command_ = nullptr;

        *main_command_ = new AbstractCommand();
        setText("Empty cue");
        qDebug() << "ProgrammingButton::onSaveClicked() --> командна не сохранена. Нет подходящих каналов";
    }

    emit Mediator::instance().SelectingCommand();
}

void ProgrammingButton::SetupUi() {
    setFixedSize(60, 60);

    qdial_save_command_ = new QDialogCommand(this);
}

void ProgrammingButton::SetupConnections() {
    connect(qdial_save_command_, &QDialogCommand::SaveClicked, this, &ProgrammingButton::onSaveClicked);
}

void ProgrammingButton::drawBackground(QPainter& painter) {
    QBrush brush (QColor(29, 33, 34));

    if (isDown()) {
        brush.setColor(QColor(59, 63, 64));
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 10, 10);
}

void ProgrammingButton::drawBorder(QPainter& painter) {
    QPen pen(QColor(96, 102, 104));

    if (isDown()) {
        pen.setColor(QColor(118, 156, 227));
    }

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 10, 10);
}

void ProgrammingButton::drawText(QPainter& painter) {
    QFont new_font = font();
    new_font.setPointSize(8);

    painter.setPen(Qt::white);
    painter.setFont(new_font);
    painter.drawText(rect(), Qt::AlignCenter, QString::number(number_));
    painter.drawText(rect().adjusted(0, 25, 0, 0), Qt::TextWordWrap | Qt::AlignCenter, text());
}
