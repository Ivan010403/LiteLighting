#include "settingswindow.h"

SettingsWindow::SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    QWidget(parent)
{
    SetupUi();
    SetupConnections();
}

void SettingsWindow::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // по каждому автомату и суммарная мощность
    PaintElectrPerAutomat(painter);

    // главный автомат и суммарная мощность
    PaintTotal(painter);

    // данные по каждой фазе
    PaintElectrPerPhase(painter);
}

void SettingsWindow::PaintElectrPerAutomat(QPainter& painter) {
    const auto& vector = CircuitBreaker::instance().data_of_breakers;

    for (int i = 0; i < vector.size(); ++i) {
        QLayoutItem* item = hlayout_patching_->itemAt(i+2);

        QPoint globalPos = item->layout()->itemAt(2)->widget()->mapToGlobal(QPoint(0, 0));

        QPoint localTopLeft = this->mapFromGlobal(globalPos);

        int init_x = localTopLeft.x();
        int init_y = localTopLeft.y();
        int width = item->layout()->itemAt(2)->widget()->width();
        int height = item->layout()->itemAt(2)->widget()->height();

        QFont new_font = font();
        new_font.setPointSize(10);

        QRect rect = QRect(init_x, init_y + height + 10, width, 50);

        painter.setPen(Qt::white);
        painter.setFont(new_font);
        painter.drawText(rect.adjusted(3, 10, 0, -3), Qt::AlignTop | Qt::AlignHCenter, QString("Curr: ") + QString::number(vector[i].second));
        painter.drawText(rect.adjusted(3, 25, 0, -3), Qt::TextWordWrap | Qt::AlignCenter, QString("Max: ") + QString::number(CircuitBreaker::instance().getBreakerAmperage(i) * 220));

        QPen pen;
        pen.setWidth(2);
        pen.setColor((vector[i].second > CircuitBreaker::instance().getBreakerAmperage(i) * 220) ? QColor(Qt::red) : QColor(118, 156, 227));

        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect.adjusted(3, 5, -3, 0), 8, 8);
    }
}

void SettingsWindow::PaintTotal(QPainter& painter) {
    if (CircuitBreaker::instance().amperage_ != 0) {
        QLayoutItem* item = hlayout_patching_->itemAt(1);

        QPoint globalPos = item->widget()->mapToGlobal(QPoint(0, 0));

        QPoint localTopLeft = this->mapFromGlobal(globalPos);

        int init_x = localTopLeft.x();
        int init_y = localTopLeft.y();
        int width = item->widget()->width();
        int height = item->widget()->height();

        QFont new_font = font();
        new_font.setPointSize(10);

        QRect rect = QRect(init_x, init_y + height + 36, width, 50);

        painter.setPen(Qt::white);
        painter.setFont(new_font);
        painter.drawText(rect.adjusted(3, 10, 0, -3), Qt::AlignTop | Qt::AlignHCenter, QString("Curr: ") + QString::number(CircuitBreaker::instance().total_power_));
        painter.drawText(rect.adjusted(3, 25, 0, -3), Qt::TextWordWrap | Qt::AlignCenter, QString("Max: ") + QString::number(CircuitBreaker::instance().amperage_ * 220 * 3));

        QPen pen;
        pen.setWidth(2);
        pen.setColor((CircuitBreaker::instance().total_power_ > CircuitBreaker::instance().amperage_ * 220) ? QColor(Qt::red) : QColor(118, 156, 227));

        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect.adjusted(3, 5, -3, 0), 8, 8);
    }
}

void SettingsWindow::PaintElectrPerPhase(QPainter& painter) {
    if ((CircuitBreaker::instance().amperage_ != 0) && (CircuitBreaker::instance().size())) {
        QLayoutItem* item = hlayout_patching_->itemAt(1);

        QPoint globalPos = item->widget()->mapToGlobal(QPoint(0, 0));
        QPoint localTopLeft = this->mapFromGlobal(globalPos);

        int init_x = localTopLeft.x();
        int init_y = localTopLeft.y();
        int height = item->widget()->height();

        item = hlayout_patching_->itemAt(CircuitBreaker::instance().size() + 1);

        globalPos = item->layout()->itemAt(2)->widget()->mapToGlobal(QPoint(0, 0));
        localTopLeft = this->mapFromGlobal(globalPos);

        int last_x = localTopLeft.x() + item->layout()->itemAt(2)->widget()->width();

        int width_phase_rect = (last_x - init_x) / 3;

        for (int i = 0; i < 3 ; ++i) {
            QFont new_font = font();
            new_font.setPointSize(10);

            QRect rect = QRect(init_x + width_phase_rect * i, init_y + height + 100, width_phase_rect, 50);

            painter.setPen(Qt::white);
            painter.setFont(new_font);
            painter.drawText(rect.adjusted(3, 10, 0, -3), Qt::AlignTop | Qt::AlignHCenter, QString("Phase ") + QString::number(i + 1) +QString(": ") + QString::number(CircuitBreaker::instance().phase_powers_[i]));
            painter.drawText(rect.adjusted(3, 25, 0, -3), Qt::TextWordWrap | Qt::AlignCenter, QString("Max: ") + QString::number(CircuitBreaker::instance().amperage_  * 220));

            QPen pen;
            pen.setWidth(2);
            pen.setColor((CircuitBreaker::instance().phase_powers_[i] > CircuitBreaker::instance().amperage_ * 220 / 3) ? QColor(Qt::red) : QColor(118, 156, 227));

            painter.setPen(pen);
            painter.setBrush(Qt::NoBrush);
            painter.drawRoundedRect(rect.adjusted(3, 5, -3, 0), 8, 8);
        }
    }
}

void SettingsWindow::onLoadClicked() {
    QFile file("showfile.json");
    if (!file.open(QIODevice::ReadOnly)) return; // обработать нормально - а что если не открылось?

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject root = doc.object();


    dmx_fixture_array_->LoadDataFromShow(root);

    CommandArray::instance().LoadDataFromShow(root, dmx_fixture_array_);

    emit Mediator::instance().LoadBuskFromShow();
}

void SettingsWindow::onSaveClicked() {
    QJsonObject root;

    dmx_fixture_array_->SaveDataToShow(root);

    CommandArray::instance().SaveDataToShow(root);

    emit Mediator::instance().SaveBuskToShow();

    QFile file("showfile.json");
    if (!file.open(QIODevice::WriteOnly)) { // а что если не открылось?
        qDebug() << "Ошибка открытия файла для записи";
    }

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
}

void SettingsWindow::onEnteringData(int value) {
    for (int i = CircuitBreaker::instance().size(); i < value; ++i) {
        QLabel* temp = new QLabel(this);
        temp->setFixedSize(80, 300);
        temp->setPixmap(pixmap_C16_);
        temp->setScaledContents(true);

        QComboBox* cmb_box = new QComboBox(this);
        cmb_box->setObjectName(QString::number(i));
        cmb_box->setFixedWidth(100);
        cmb_box->addItem("Clear");
        cmb_box->addItem("1st phase");
        cmb_box->addItem("2nd phase");
        cmb_box->addItem("3rd phase");
        cmb_box->setFixedWidth(80);

        QSpinBox* spn_box = new QSpinBox(this);
        spn_box->setMaximum(250);
        spn_box->setFixedWidth(80);
        spn_box->setObjectName("exactly!");

        QVBoxLayout* vlayout = new QVBoxLayout();
        vlayout->setContentsMargins(0,0,0,0);
        vlayout->setSpacing(0);

        vlayout->addWidget(temp);
        vlayout->addWidget(cmb_box);
        vlayout->addWidget(spn_box);

        if (hlayout_patching_->count() > 1) {
            QLayoutItem* last = hlayout_patching_->takeAt(hlayout_patching_->count()-1);

            if (last->spacerItem()) delete last->spacerItem();
        }

        hlayout_patching_->addLayout(vlayout, Qt::AlignTop);
        hlayout_patching_->addStretch();

        ++CircuitBreaker::instance();

        update();
    }
}

void SettingsWindow::onSetupClicked() {
    for (int i = 2; i < hlayout_patching_->count() - 1; ++i) {
        QLayoutItem* item = hlayout_patching_->itemAt(i);

        int phase_number = qobject_cast<QComboBox*>(item->layout()->itemAt(1)->widget())->currentIndex();
        int breaker_amperage = qobject_cast<QSpinBox*>(item->layout()->itemAt(2)->widget())->value();

        CircuitBreaker::instance().AddBreaker(i - 2, phase_number, breaker_amperage);
    }

    CircuitBreaker::instance().SetAmperage(spnbox_edit_amperage_->value());
    update();
    emit CircuitBreaker::instance().UploadingData();
}

void SettingsWindow::SetupUi() {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(20, 20, 20, 20);
    gridlayout_main_->setSpacing(20);

    btn_load_showfile_ = new QPushButton("Load show", this);
    btn_load_showfile_->setFixedHeight(60);
    btn_load_showfile_->setFixedWidth(600);

    btn_save_showfile_ = new QPushButton("Save show", this);
    btn_save_showfile_->setFixedHeight(60);
    btn_save_showfile_->setFixedWidth(600);


    QVBoxLayout* layout_amperage = new QVBoxLayout();
    layout_amperage->setContentsMargins(0, 0, 0, 0);
    layout_amperage->setSpacing(10);

    label_amperage_ = new QLabel("Enter amperage", this);

    spnbox_edit_amperage_ = new QSpinBox(this);
    spnbox_edit_amperage_->setMaximum(10000);

    layout_amperage->addWidget(label_amperage_, 1, Qt::AlignHCenter);
    layout_amperage->addWidget(spnbox_edit_amperage_, Qt::AlignHCenter);


    QVBoxLayout* layout_amount = new QVBoxLayout();
    layout_amount->setContentsMargins(0, 0, 0, 0);
    layout_amount->setSpacing(10);

    label_amount_ = new QLabel("Enter amount", this);

    spnbox_edit_amount_ = new QSpinBox(this);
    spnbox_edit_amount_->setMaximum(15);

    layout_amount->addWidget(label_amount_, 1, Qt::AlignHCenter);
    layout_amount->addWidget(spnbox_edit_amount_, Qt::AlignHCenter);

    QWidget* cont_patching_ = new QWidget(this);
    cont_patching_->setMinimumHeight(400);

    hlayout_patching_ = new QHBoxLayout(cont_patching_);
    hlayout_patching_->setSpacing(0);
    hlayout_patching_->setContentsMargins(0, 0, 0, 0);
    hlayout_patching_->setAlignment(Qt::AlignTop);

    QLabel* c100 = new QLabel(this);
    c100->setFixedSize(315, 300);
    c100->setPixmap(pixmap_C100_);
    c100->setScaledContents(true);

    if (hlayout_patching_->count() == 0) hlayout_patching_->addStretch();
    hlayout_patching_->addWidget(c100);
    hlayout_patching_->addStretch();

    for_painting_ = new QWidget(this);
    for_painting_->setFixedHeight(100);

    btn_setup_electrical_ = new QPushButton("Setup", this);
    btn_setup_electrical_->setFixedHeight(30);


    gridlayout_main_->addWidget(btn_load_showfile_, 0, 0, 2, 1, Qt::AlignHCenter);
    gridlayout_main_->addWidget(btn_save_showfile_, 0, 1, 2, 1, Qt::AlignHCenter);

    gridlayout_main_->addLayout(layout_amperage, 2, 0, 1, 1);

    gridlayout_main_->addLayout(layout_amount, 2, 1, 1, 1);

    gridlayout_main_->addWidget(cont_patching_, 3, 0, 1, 2);

    gridlayout_main_->addWidget(for_painting_, 4, 0, 1, 2);

    gridlayout_main_->addWidget(btn_setup_electrical_, 5, 0, 1, 2);
}

void SettingsWindow::SetupConnections() {
    connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
    connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);

    connect(spnbox_edit_amount_, &QSpinBox::valueChanged, this, &SettingsWindow::onEnteringData);
    connect(btn_setup_electrical_, &QPushButton::clicked, this, &SettingsWindow::onSetupClicked);
}
