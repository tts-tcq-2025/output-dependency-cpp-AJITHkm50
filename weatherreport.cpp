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
        double temperature = sensor.TemperatureInC();
        int windSpeed = sensor.WindSpeedKMPH();
        string report = "Sunny Day";

        // Early warning logic (Extension 1)
        // Example temperature limits: 0 (low), 40 (high)
        double tempLow = 0.0, tempHigh = 40.0;
        double tempWarnTol = 0.015 * tempHigh;
        if (temperature >= tempLow && temperature < tempLow + tempWarnTol)
            std::cout << "Warning: Approaching hypothermia\n";
        if (temperature > tempHigh - tempWarnTol && temperature <= tempHigh)
            std::cout << "Warning: Approaching hyperthermia\n";

        // Example precipitation limits: 0 (low), 100 (high)
        int precipLow = 0, precipHigh = 100;
        double precipWarnTol = 0.015 * precipHigh;
        if (precipitation >= precipLow && precipitation < precipLow + precipWarnTol)
            std::cout << "Warning: Approaching low precipitation\n";
        if (precipitation > precipHigh - precipWarnTol && precipitation <= precipHigh)
            std::cout << "Warning: Approaching high precipitation\n";

        // Example wind speed limits: 0 (low), 100 (high)
        int windLow = 0, windHigh = 100;
        double windWarnTol = 0.015 * windHigh;
        if (windSpeed >= windLow && windSpeed < windLow + windWarnTol)
            std::cout << "Warning: Approaching calm wind\n";
        if (windSpeed > windHigh - windWarnTol && windSpeed <= windHigh)
            std::cout << "Warning: Approaching stormy wind\n";

        // Original buggy logic (unchanged)
        if (temperature > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (windSpeed > 50)
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
