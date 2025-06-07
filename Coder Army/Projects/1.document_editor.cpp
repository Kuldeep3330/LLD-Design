#include <bits/stdc++.h>

using namespace std;

// User will be  Riders and Drivers.
class User
{
protected:
    int id;
    string name;
    int phone;
    double latitude;
    double longitude;

public:
    User(int id, const string &name, int phone, double latitude, double longitude)
        : id(id), name(name), phone(phone), latitude(latitude), longitude(longitude) {}

    int getId() const { return id; }
    string getName() const { return name; }

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    void setLocation(double lat, double lon)
    {
        latitude = lat;
        longitude = lon;
    }
    virtual ~User() {}
};

// User is a two type Rider and Driver
class Rider : public User
{
public:
    Rider(int id, const string &name, int phone, double latitude, double longitude)
        : User(id, name, phone, latitude, longitude) {}
};

class Driver : public User
{
private:
    bool status; // by default true means available / false means on-trip

public:
    Driver(int id, const string &name, int phone, double latitude, double longitude)
        : User(id, name, phone, latitude, longitude), status(true) {}

    void setStatus(bool status) { this->status = status; }
    bool isAvailable() const { return status; }
};

// Vehicle can be(e.g., “Bike”,“Sedan”, “SUV”, “Auto-Rickshaw”)
class Vehicle
{
protected:
    string licensePlate;
    string model;

public:
    Vehicle(const string &plate, const string &model)
        : licensePlate(plate), model(model) {}

    string getLicensePlate() const { return licensePlate; }
    string getModel() const { return model; }

    virtual ~Vehicle() {}
};

// enum for Ride status
enum class RideStatus
{
    REQUESTED,
    ONGOING,
    COMPLETED,
    CANCELLED
};

// Ride class
class Ride
{
private:
    Rider *rider;
    Driver *driver;
    Vehicle *vehicle;
    RideStatus status;

public:
    Ride(Rider *rider, Driver *driver, Vehicle *vehicle)
        : rider(rider), driver(driver), vehicle(vehicle), status(RideStatus::REQUESTED) {}

    void startRide() { status = RideStatus::ONGOING; }
    void completeRide() { status = RideStatus::COMPLETED; }
    void cancelRide() { status = RideStatus::CANCELLED; }

    RideStatus getStatus() const { return status; }

    Rider *getRider() const { return rider; }
    Driver *getDriver() const { return driver; }
    Vehicle *getVehicle() const { return vehicle; }
};
// Driver matching strategy
class IDriverMatchingStrategy
{
public:
    virtual Driver *findDriver(Rider *rider, const std::vector<Driver *> &drivers) = 0;
    virtual ~IDriverMatchingStrategy() {}
};

class NearestDriverStrategy : public IDriverMatchingStrategy
{
public:
    Driver *findDriver(Rider *rider, const std::vector<Driver *> &drivers) override
    {
        double minDistance = std::numeric_limits<double>::max();
        Driver *bestDriver = nullptr;

        for (Driver *driver : drivers)
        {
            if (!driver->isAvailable())
                continue;

            double dx = driver->getLatitude() - rider->getLatitude();
            double dy = driver->getLongitude() - rider->getLongitude();
            double dist = std::sqrt(dx * dx + dy * dy);

            if (dist < minDistance)
            {
                minDistance = dist;
                bestDriver = driver;
            }
        }

        return bestDriver;
    }
};

// Fare Calculator using Decorator Pattern
class IFareCalculator
{
public:
    virtual double calculateFare(double baseDistanceKm) = 0;
    virtual ~IFareCalculator() {}
};

class BaseFareCalculator : public IFareCalculator
{
public:
    double calculateFare(double baseDistanceKm) override
    {
        return baseDistanceKm * 10.0;
    }
};

class FareDecorator : public IFareCalculator
{
protected:
    IFareCalculator *inner;

public:
    FareDecorator(IFareCalculator *calc) : inner(calc) {}
    virtual ~FareDecorator() { delete inner; } // Clean up wrapped object
};

// SurgePricingDecorator (1.5x multiplier)
class SurgePricingDecorator : public FareDecorator
{
public:
    SurgePricingDecorator(IFareCalculator *calc) : FareDecorator(calc) {}

    double calculateFare(double baseDistanceKm) override
    {
        double fare = inner->calculateFare(baseDistanceKm);
        return fare * 1.5;
    }
};

// DiscountDecorator (apply ₹20 discount)
class DiscountDecorator : public FareDecorator
{
public:
    DiscountDecorator(IFareCalculator *calc) : FareDecorator(calc) {}

    double calculateFare(double baseDistanceKm) override
    {
        double fare = inner->calculateFare(baseDistanceKm);
        return fare - 20.0 > 0 ? fare - 20.0 : 0.0;
    }
};

// notification using observer pattern
class IRideEventListener
{
public:
    virtual void onRideStatusChanged(int rideId, const std::string &status) = 0;
    virtual ~IRideEventListener() {}
};

class NotificationService
{
private:
    std::vector<IRideEventListener *> listeners;

public:
    void subscribe(IRideEventListener *listener)
    {
        listeners.push_back(listener);
    }

    void unsubscribe(IRideEventListener *listener)
    {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
    }

    void notify(int rideId, const std::string &status)
    {
        for (auto *listener : listeners)
        {
            listener->onRideStatusChanged(rideId, status);
        }
    }
};

// implement concrete
class RiderApp : public IRideEventListener
{
public:
    void onRideStatusChanged(int rideId, const std::string &status) override
    {
        std::cout << "[Rider App] Ride #" << rideId << " status changed to: " << status << std::endl;
    }
};

class DriverApp : public IRideEventListener
{
public:
    void onRideStatusChanged(int rideId, const std::string &status) override
    {
        std::cout << "[Driver App] Ride #" << rideId << " status changed to: " << status << std::endl;
    }
};

class RideManager
{
private:
    std::vector<Rider *> riders;
    std::vector<Driver *> drivers;
    std::vector<std::unique_ptr<Ride>> rides;
    std::unique_ptr<IDriverMatchingStrategy> matchingStrategy;
    NotificationService *notifier = nullptr;

    RideManager() {}

public:
    static RideManager &getInstance()
    {
        static RideManager instance;
        return instance;
    }

    void setNotifier(NotificationService *ns)
    {
        notifier = ns;
    }

    void setMatchingStrategy(IDriverMatchingStrategy *strategy)
    {
        matchingStrategy.reset(strategy);
    }

    void registerRider(Rider *rider)
    {
        riders.push_back(rider);
    }

    void registerDriver(Driver *driver)
    {
        drivers.push_back(driver);
    }

    Ride *requestRide(Rider *rider)
    {
        if (!matchingStrategy)
            return nullptr;

        Driver *matchedDriver = matchingStrategy->findDriver(rider, drivers);
        if (!matchedDriver)
            return nullptr;

        matchedDriver->setStatus(false);
        Vehicle *vehicle = new Vehicle("AB123", "Sedan");
        auto ride = std::make_unique<Ride>(rider, matchedDriver, vehicle);
        Ride *ridePtr = ride.get();

        ride->startRide(); // start immediately for demo

        if (notifier)
        {
            notifier->notify(rides.size(), "ONGOING");
        }

        rides.push_back(std::move(ride));
        return ridePtr;
    }

    // Disable copy/move
    RideManager(const RideManager &) = delete;
    RideManager &operator=(const RideManager &) = delete;
};
void testFareCalculator()
{

    double distance = 5.0; // 5 km

    // Base fare
    IFareCalculator *base = new BaseFareCalculator();
    std::cout << "Base Fare: ₹" << base->calculateFare(distance) << std::endl;

    // With surge
    IFareCalculator *surge = new SurgePricingDecorator(new BaseFareCalculator());
    std::cout << "With Surge: ₹" << surge->calculateFare(distance) << std::endl;

    // With surge + discount
    IFareCalculator *surgeAndDiscount = new DiscountDecorator(
        new SurgePricingDecorator(new BaseFareCalculator()));
    std::cout << "Surge + Discount: ₹" << surgeAndDiscount->calculateFare(distance) << std::endl;

    delete base;
    delete surge;
    delete surgeAndDiscount;
}

int main()
{
    Rider *rider1 = new Rider(1, "Alice", 9999999999, 10.0, 10.0);
    Driver *driver1 = new Driver(2, "Bob", 8888888888, 10.2, 10.1);

    RiderApp riderApp;
    DriverApp driverApp;

    NotificationService notificationService;
    notificationService.subscribe(&riderApp);
    notificationService.subscribe(&driverApp);

    RideManager &manager = RideManager::getInstance();
    manager.setMatchingStrategy(new NearestDriverStrategy());
    manager.setNotifier(&notificationService);

    manager.registerRider(rider1);
    manager.registerDriver(driver1);

    Ride *ride = manager.requestRide(rider1);

    if (ride)
    {
        std::cout << "Ride started!" << std::endl;
    }
    else
    {
        std::cout << "No drivers available." << std::endl;
    }

    testFareCalculator();

    delete rider1;
    delete driver1;

    return 0;
}
