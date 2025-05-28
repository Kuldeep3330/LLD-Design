#include <iostream>
using namespace std;

// Media Player
/*
Scenario:
A media player supports playing MP3 files but needs to support other formats like MP4 and VLC without modifying its existing implementation.
*/
// // Target Interface
// class MediaPlayer
// {
// public:
//     virtual void play(const string &audioType, const string &fileName) = 0;
//     virtual ~MediaPlayer() = default;
// };
// // Adaptee
// class AdvancedMediaPlayer
// {
// public:
//     virtual void playVlc(const string &fileName) = 0;
//     virtual void playMp4(const string &fileName) = 0;
//     virtual ~AdvancedMediaPlayer() {}
// };
// class VlcPlayer : public AdvancedMediaPlayer
// {
// public:
//     void playVlc(const string &fileName) override
//     {
//         cout << "Playing VLC file: " << fileName << endl;
//     }

//     void playMp4(const string &fileName) override
//     {
//         // Do nothing
//     }
// };

// class Mp4Player : public AdvancedMediaPlayer
// {
// public:
//     void playVlc(const string &fileName) override
//     {
//         // Do nothing
//     }

//     void playMp4(const string &fileName) override
//     {
//         cout << "Playing MP4 file: " << fileName << endl;
//     }
// };
// // Adapter
// class MediaAdapter : public MediaPlayer
// {
// private:
//     AdvancedMediaPlayer *advancedPlayer;

// public:
//     MediaAdapter(const string &audioType)
//     {
//         if (audioType == "vlc")
//             advancedPlayer = new VlcPlayer();
//         else if (audioType == "mp4")
//         {
//             advancedPlayer = new Mp4Player();
//         }
//     }
//     void play(const string &audioType, const string &fileName) override
//     {
//         if (audioType == "vlc")
//         {
//             advancedPlayer->playVlc(fileName);
//         }
//         else if (audioType == "mp4")
//         {
//             advancedPlayer->playMp4(fileName);
//         }
//     }
//     ~MediaAdapter()
//     {
//         delete advancedPlayer;
//     }
// };

// // concrete Target
// class AudioPlayer : public MediaPlayer
// {
// public:
//     void play(const string &audioType, const string &fileName) override
//     {
//         if (audioType == "mp3")
//         {
//             cout << "Playing MP3 file: " << fileName << endl;
//         }
//         else if (audioType == "vlc" || audioType == "mp4")
//         {
//             MediaPlayer *adapter = new MediaAdapter(audioType);
//             adapter->play(audioType, fileName);
//             delete adapter;
//         }
//         else
//         {
//             cout << "Invalid media type: " << audioType << endl;
//         }
//     }
// };

// payment gateway integration
// Scenario
/*
Your application supports a payment system that uses a legacy API (OldPaymentProcessor), but a new API (NewPaymentProcessor) is introduced. You need to adapt the new API to the old interface so the existing client code works seamlessly.
*/
// Target Interface
// class PaymentProcessor
// {
// public:
//     virtual void pay(int amount) const = 0;
//     virtual ~PaymentProcessor() = default;
// };
// // Adaptee
// class NewPaymentProcessor
// {
// public:
//     void makePayment(double amount) const
//     {
//         cout << "Payment of $" << amount << " processed through the new system." << endl;
//     }
// };
// // Adapter
// class PaymentAdapter : public PaymentProcessor
// {
// private:
//     NewPaymentProcessor *newProcessor;

// public:
//     PaymentAdapter(NewPaymentProcessor *processor) : newProcessor(processor) {}
//     void pay(int amount) const override
//     {
//         newProcessor->makePayment(static_cast<double>(amount));
//     }
// };

/*
Voltage Adapter
Scenario:
A device (like a laptop charger) operates at 120V, but your power source supplies 240V. Use an adapter to convert the voltage.
*/
// Target Interface
class VoltageDevice
{
public:
    virtual void useDevice() const = 0;
    virtual ~VoltageDevice() = default;
};
// 2. Adaptee
class HighVoltage
{
public:
    void supplyHighVoltage() const
    {
        cout << "Supplying 240V power " << endl;
    }
};
// 3. Adapter
class VoltageAdapter : public VoltageDevice
{
private:
    HighVoltage *highVoltage;

public:
    VoltageAdapter(HighVoltage *highVoltage) : highVoltage(highVoltage) {}
    void useDevice() const override
    {
        cout << "Converting 240V to 120V for the device." << endl;
        highVoltage->supplyHighVoltage();
    }
};
int main()
{
    // client code for voltage adapter
    HighVoltage *highVoltage = new HighVoltage();
    VoltageDevice *adapter = new VoltageAdapter(highVoltage);

    adapter->useDevice();

    delete adapter;
    delete highVoltage;

    // client code for payment integration
    // NewPaymentProcessor *newPaymentProcessor = new NewPaymentProcessor();
    // PaymentProcessor *paymentAdapter = new PaymentAdapter(newPaymentProcessor);
    // paymentAdapter->pay(100);
    // delete paymentAdapter;
    // delete newPaymentProcessor;

    // MediaPlayer *player = new AudioPlayer();

    // player->play("mp3", "song.mp3");
    // player->play("mp4", "video.mp4");
    // player->play("vlc", "movie.vlc");
    // player->play("avi", "documentary.avi");

    // delete player;
    return 0;
}