#include <iostream>
#include <vector> 

class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class WeatherStation {
private:
    float temperature;
    float humidity;
    float pressure;
    std::vector<Observer *> observers;
public:
    void registerObserver(Observer *observer) {
        observers.push_back(observer);
    }
    void removeObserver(Observer *observer) {}
    void notifyObservers() {
        for(Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }
};

class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) {
        std::cout << "Display: Temperature = " << temperature << ", Humidity = " << humidity << "%, Pressure = " << pressure << " hPa" << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;

    Display display1;
    Display display2;

    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    weatherStation.setMeasurements(25.5, 60, 1013.2);
    weatherStation.setMeasurements(24.8, 58, 1014.5);

    return 0;
}