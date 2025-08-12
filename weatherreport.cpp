#include <string>
#include <iostream>
#include <cassert>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };

    class SensorStub : public IWeatherSensor {
    private:
        double temperature;
        int precipitation;
        int humidity;
        int windSpeed;

    public:
        SensorStub(double temp, int precip, int hum, int wind)
            : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}

        double TemperatureInC() const override {
            return temperature;
        }

        int Precipitation() const override {
            return precipitation;
        }

        int Humidity() const override {
            return humidity;
        }

        int WindSpeedKMPH() const override {
            return windSpeed;
        }
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestRainy()
    {
        SensorStub sensor(26, 70, 72, 52);
        string report = Report(sensor);
        assert(report.find("rain") != string::npos); // Check for rain in the report
    }

    void TestHighPrecipitation()
    {
        SensorStub sensor(26, 70, 72, 40);
        string report = Report(sensor);
        assert(report.find("rain") != string::npos); // Check for rain in the report
    }
}
