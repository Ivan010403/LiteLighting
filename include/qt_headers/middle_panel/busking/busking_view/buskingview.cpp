#include "buskingview.h"

BuskingView::BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    selected_fixture_(selected_fixture),
    btn_move_(btn_move),
    QWidget(parent)
{
    SetupConnections();
}

void BuskingView::onBtnAddClicked() {
    if (qvect_fixture_buttons_.size() < dmx_fixture_array_->FixtureAmount()) {
        qvect_fixture_buttons_.push_back(new FixtureButton(dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByIndex(qvect_fixture_buttons_.size()), 0, 0, this));
        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::GroupChoosen, this, &BuskingView::SelectingByGroup);
        connect(this, &BuskingView::SelectingByGroup, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::SelectedByGroup);

        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::FixtureChoosen, this, &BuskingView::PressingByFixture);
        connect(this, &BuskingView::PressingByFixture, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::PressedByFixture);
    }
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

        qvect_fixture_buttons_.push_back(new FixtureButton(dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByFixtureId(fix_id), pos_x, pos_y, this));
    }
}

void BuskingView::SetupConnections() {
    connect(&Mediator::instance(), &Mediator::SaveBuskToShow, this, &BuskingView::SaveToShow);
    connect(&Mediator::instance(), &Mediator::LoadBuskFromShow, this, &BuskingView::LoadFromShow);
}
