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
    //--------------------constructors and destructor--------------------------------
    explicit DmxGateway(unsigned int universe_amount, QObject *parent = nullptr);

    ~DmxGateway() = default;
    //-------------------------------------------------------------------------------


    //--------------------function for table model-----------------------------------
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    // дописать функцию по аналогии с fixture array!!!!!!!!!
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //-------------------------------------------------------------------------------


    //---------------------------local functions-------------------------------------
    bool Start();
    void Stop();
    ola::DmxBuffer* GetBuffer(unsigned int universe_id);
    // refactor!!!
    unsigned int GetAmountUniv() const;
    //-------------------------------------------------------------------------------


    //---------------------------deleted functions-----------------------------------
    DmxGateway() = delete;
    DmxGateway(const DmxGateway& dmx_gtw) = delete;
    DmxGateway(DmxGateway&& dmx_gtw) = delete;
    DmxGateway& operator= (const DmxGateway& dmx_gtw) = delete;
    DmxGateway& operator= (DmxGateway&& dmx_gtw) = delete;
    //-------------------------------------------------------------------------------
protected:
    void* Run();

private:
    //---------------------------private functions-----------------------------------
    void GatewaySetup();
    void ConnectionClosed();
    bool SendData();
    //-------------------------------------------------------------------------------


    std::vector <ola::DmxBuffer> dmx_data_;
    unsigned int universe_amount_;

    const ola::client::SendDMXArgs casual_dmx_args_ = ola::client::SendDMXArgs();

    ola::client::OlaClientWrapper wrapper_;
    ola::io::SelectServer* select_server_ = nullptr;
    ola::client::OlaClient* ola_client_ = nullptr;

    // const ola::TimeInterval ola_second_ = ola::TimeInterval(1000000);
    const ola::TimeInterval ola_30_fps_ = ola::TimeInterval(33333); // not 30 fps, but 30.003...
};

#endif // DMXGATEWAY_H
