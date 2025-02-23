#ifndef DMXGATEWAY_H
#define DMXGATEWAY_H
#include <ola/io/SelectServer.h>
#include <ola/client/ClientWrapper.h>
#include <ola/thread/Thread.h>
#include <ola/Callback.h>
#include <ola/DmxBuffer.h>
#include <ola/Logging.h> // снова перепроверить все заголовочные файлы

#include <QtWidgets>
#include <vector>


class DmxGateway : public QAbstractTableModel, public ola::thread::Thread {
    Q_OBJECT

public:

    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); // зачем?
        return universe_amount_;
    }

    int columnCount(const QModelIndex &parent) const {
        Q_UNUSED(parent);
        return ola::DMX_MAX_SLOT_NUMBER; // convers from uint16_t to int!
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const {
        if (!index.isValid()) return QVariant();

        return (role == Qt::DisplayRole || role == Qt::EditRole)
                ? dmx_data_[index.row()].Get(index.column())
                : QVariant();
    }


    // ------------------------------------------------------

    DmxGateway(unsigned int universe_amount, QObject *parent = 0) :
        dmx_data_(universe_amount),
        universe_amount_(universe_amount),
        QAbstractTableModel(parent)
    {
        ola::InitLogging(ola::OLA_LOG_INFO, ola::OLA_LOG_STDERR);

        for (int i = 0; i < universe_amount_; ++i) {
            dmx_data_[i].Blackout();
        }
    }

    ~DmxGateway() = default;

    //-----------------------------------------------------------------------------------------------------------

    bool Start();

    void Stop();

    ola::DmxBuffer& GetBuffer(unsigned int universe_id);

    unsigned int GetAmountUniv() {
        return universe_amount_;
    }

    DmxGateway() = delete;
    DmxGateway(const DmxGateway& dmx_gtw) = delete;
    DmxGateway(DmxGateway&& dmx_gtw) = delete;
    DmxGateway& operator= (const DmxGateway& dmx_gtw) = delete;
    DmxGateway& operator= (DmxGateway&& dmx_gtw) = delete;
protected:
    void* Run();

private:
    void GatewaySetup();

    void ConnectionClosed();

    bool SendData();

    std::vector <ola::DmxBuffer> dmx_data_;
    unsigned int universe_amount_;

    const ola::client::SendDMXArgs casual_dmx_args_ = ola::client::SendDMXArgs();

    ola::client::OlaClientWrapper wrapper_;
    ola::io::SelectServer* select_server_ = nullptr;
    ola::client::OlaClient* ola_client_ = nullptr;

    const ola::TimeInterval ola_second_ = ola::TimeInterval(1000000);
    const ola::TimeInterval ola_30_fps_ = ola::TimeInterval(33333); // not 30 fps, but 30.003...
};

#endif // DMXGATEWAY_H
