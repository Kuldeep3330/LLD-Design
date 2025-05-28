#include <iostream>
using namespace std;
/*
Example: Home Theater System
Scenario:
You have a home theater system with multiple components: a DVD Player, a Projector, a Sound System, and Lights. Instead of controlling each component individually, a HomeTheaterFacade provides a unified interface to operate the system.
*/
// 1.subsystem
class DVDPlayer
{
public:
    void on() { cout << "DVD Player is ON." << endl; }
    void play(const string &movie) { cout << "Playing movie: " << movie << endl; }
    void off() { cout << "DVD Player is OFF." << endl; }
};

class Projector
{
public:
    void on() { cout << "Projector is ON." << endl; }
    void setInput(const string &input) { cout << "Projector input set to: " << input << endl; }
    void off() { cout << "Projector is OFF." << endl; }
};

class SoundSystem
{
public:
    void on() { cout << "Sound System is ON." << endl; }
    void setVolume(int level) { cout << "Sound System volume set to: " << level << endl; }
    void off() { cout << "Sound System is OFF." << endl; }
};

class Lights
{
public:
    void dim(int level) { cout << "Lights dimmed to: " << level << "%" << endl; }
    void on() { cout << "Lights are ON." << endl; }
};

// Facade
class HomeTheaterFacade
{
private:
    DVDPlayer *dvdPlayer;
    Projector *projector;
    SoundSystem *soundSystem;
    Lights *lights;

public:
    HomeTheaterFacade(DVDPlayer *dvdPlayer,
                      Projector *projector,
                      SoundSystem *soundSystem,
                      Lights *lights) : dvdPlayer(dvdPlayer), projector(projector), soundSystem(soundSystem), lights(lights)
    {
    }
    void watchMovie(const string &movie)
    {
        cout << "starting the hoome theater.....\n";
        lights->dim(20);
        projector->on();
        projector->setInput("DVD");
        soundSystem->on();
        soundSystem->setVolume(80);
        dvdPlayer->on();
        dvdPlayer->play(movie);
    }
    void endMovie()
    {
        cout << "\nShutting down the home theater...\n";
        dvdPlayer->off();
        projector->off();
        soundSystem->off();
        lights->on();
    }
};

// 2.Travel booking system
/*
A travel booking system involves multiple subsystems: Flight Booking, Hotel Booking, and Car Rental. The TravelFacade simplifies the booking process.
*/
class FlightBooking
{
public:
    void bookFlight()
    {
        cout << "Flight booking\n";
    }
};
class HotelBooking
{
public:
    void bookHotel()
    {
        cout << "Hotel booking\n";
    }
};
class CarRental
{
public:
    void rentCar()
    {
        cout << "Car rented\n";
    }
};
// Facade
class TravelFacade
{
private:
    FlightBooking *flightBooking;
    HotelBooking *hotelBooking;
    CarRental *carRental;

public:
    TravelFacade(FlightBooking *flightBooking,
                 HotelBooking *hotelBooking,
                 CarRental *carRental) : flightBooking(flightBooking), hotelBooking(hotelBooking), carRental(carRental) {}
    void bookCompleteTravel()
    {
        cout << "Booking complete travel package\n";
        flightBooking->bookFlight();
        hotelBooking->bookHotel();
        carRental->rentCar();
    }
};
int main()
{
    // client code for hotel booking
    FlightBooking *flight;
    HotelBooking *hotel;
    CarRental *car;
    TravelFacade *facade = new TravelFacade(flight, hotel, car);
    facade->bookCompleteTravel();
    // client code for home theater
    //  DVDPlayer dvdPlayer;
    //  Projector projector;
    //  SoundSystem soundSystem;
    //  Lights lights;

    // HomeTheaterFacade homeTheater(&dvdPlayer, &projector, &soundSystem, &lights);

    // homeTheater.watchMovie("Marco");
    // homeTheater.endMovie();
    return 0;
}