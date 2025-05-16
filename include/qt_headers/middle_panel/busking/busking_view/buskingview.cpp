#include "buskingview.h"

BuskingView::BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    selected_fixture_(selected_fixture),
    btn_move_(btn_move),
    QWidget(parent)
{
    selected_fixture_button_ = new FixtureButton*;
    *selected_fixture_button_ = nullptr;

    SetupConnections();
}

BuskingView::~BuskingView() {
    delete selected_fixture_button_;
}

void BuskingView::onBtnAddClicked() {
    if (qvect_fixture_buttons_.size() < dmx_fixture_array_->FixtureAmount()) {
        qvect_fixture_buttons_.push_back(new FixtureButton(selected_fixture_button_, dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByIndex(qvect_fixture_buttons_.size()), 0, 0, this));
        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::GroupChoosen, this, &BuskingView::SelectingByGroup);
        connect(this, &BuskingView::SelectingByGroup, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::SelectedByGroup);

        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::FixtureChoosen, this, &BuskingView::PressingByFixture);
        connect(this, &BuskingView::PressingByFixture, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::PressedByFixture);
    }
}

void BuskingView::onBtnAddSocket() {
    qvect_socket_buttons_.push_back(new SocketButton(selected_fixture_button_, btn_move_, this));
    connect(qvect_socket_buttons_[qvect_socket_buttons_.size() - 1], &SocketButton::SocketPatching, this, &BuskingView::onSocketPatched);
    connect(qvect_socket_buttons_[qvect_socket_buttons_.size() - 1], &SocketButton::SocketUnpatching, this, &BuskingView::onSocketUnpatched);
}

void BuskingView::onSocketPatched(FixtureButton* btn, SocketButton* sckt, int break_number) {
    map_connected_fix_socket_[sckt].push_back(btn);
    update();
}

void BuskingView::onSocketUnpatched(FixtureButton* btn, SocketButton* sckt, int break_number) {
    auto& inner_vector = map_connected_fix_socket_[sckt];
    auto it = inner_vector.begin();

    while (it != inner_vector.end()) {
        if ((it = std::find(inner_vector.begin(), inner_vector.end(), btn)) != inner_vector.end()) {
            it = inner_vector.erase(it);
        }
    }

    if (inner_vector.size() == 0) map_connected_fix_socket_.erase(sckt);

    update();
}

void BuskingView::SaveToShow() {
    QJsonObject root;

    QJsonArray json_array;

    for (const auto& var : qvect_fixture_buttons_) {
        QJsonObject button;

        button["fixture_id"] = var->getFixId();
        button["pos_x"] = var->getPosX();
        button["pos_y"] = var->getPosY();

        json_array.append(button);
    }

    root["busking_buttons"] = json_array;

    QFile file("showfile_busking.json");
    if (!file.open(QIODevice::WriteOnly)) { // а что если не открылось?
        qDebug() << "Ошибка открытия файла для записи";
    }

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
}

void BuskingView::LoadFromShow() {
    for (int i = 0; i < qvect_fixture_buttons_.size(); ++i) {
        delete qvect_fixture_buttons_[i];
    }

    QFile file("showfile_busking.json");
    if (!file.open(QIODevice::ReadOnly)) return; // обработать нормально - а что если не открылось?

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject root = doc.object();

    QJsonArray busking_buttons = root["busking_buttons"].toArray();

    for (const auto& var : busking_buttons) {
        QJsonObject button = var.toObject();

        int fix_id = button["fixture_id"].toInt();
        int pos_x = button["pos_x"].toInt();
        int pos_y = button["pos_y"].toInt();

        qvect_fixture_buttons_.push_back(new FixtureButton(selected_fixture_button_, dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByFixtureId(fix_id), pos_x, pos_y, this));

        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::GroupChoosen, this, &BuskingView::SelectingByGroup);
        connect(this, &BuskingView::SelectingByGroup, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::SelectedByGroup);

        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::FixtureChoosen, this, &BuskingView::PressingByFixture);
        connect(this, &BuskingView::PressingByFixture, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::PressedByFixture);
    }
}

void BuskingView::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto& var : map_connected_fix_socket_) {
        int x_socket = (var.first)->x() + (var.first)->width()/2;
        int y_socket = (var.first)->y() + (var.first)->height();

        switch ((var.first)->getBreaker()) {
        case 1:
            painter.setPen(QPen(Qt::red, 1));
            break;
        case 2:
            painter.setPen(QPen(Qt::green, 1));
            break;
        case 3:
            painter.setPen(QPen(Qt::blue, 1));
            break;
        }

        for (const auto& val : var.second) {
            int x_button = val->x() + val->width()/2;
            int y_button = val->y() + val->height();

            QPainterPath path;
            if (y_socket > y_button) {
                path.moveTo(x_socket, y_socket);
                path.lineTo(x_socket, y_socket + 20);
                path.lineTo(x_button, y_socket + 20);
                path.lineTo(x_button, y_button);
            }
            else {
                path.moveTo(x_button, y_button);
                path.lineTo(x_button, y_button + 20);
                path.lineTo(x_socket, y_button + 20);
                path.lineTo(x_socket, y_socket);
            }

            painter.drawPath(path);
        }
    }
}

void BuskingView::SetupConnections() {
    connect(&Mediator::instance(), &Mediator::SaveBuskToShow, this, &BuskingView::SaveToShow);
    connect(&Mediator::instance(), &Mediator::LoadBuskFromShow, this, &BuskingView::LoadFromShow);
}
