#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

/*
  Represents a single speed sample from vehicle telemetry
*/
struct SensorSample {
    double speed;      // km/h
    long timestamp;    // milliseconds
};

/*
  Preprocess raw sensor samples:
  - Remove negative values
  - Smooth noise using moving average
*/
vector<double> preprocessSensorData(const vector<SensorSample>& samples) {
    vector<double> cleaned;

    // Remove invalid readings
    for (const auto& s : samples) {
        if (s.speed >= 0)
            cleaned.push_back(s.speed);
    }

    // Moving average smoothing (window = 3)
    vector<double> smoothed;
    int window = 3;

    for (int i = 0; i < cleaned.size(); ++i) {
        int start = max(0, i - window + 1);
        double sum = 0;
        int count = 0;

        for (int j = start; j <= i; ++j) {
            sum += cleaned[j];
            count++;
        }

        smoothed.push_back(sum / count);
    }

    return smoothed;
}

/*
  Compute acceleration values from speed samples
*/
vector<double> computeAcceleration(const vector<double>& speed) {
    vector<double> acc;

    for (int i = 1; i < speed.size(); ++i) {
        acc.push_back(speed[i] - speed[i - 1]);
    }

    return acc;
}

/*
  Classify driving behavior based on acceleration thresholds
*/
string classifyDrivingPattern(const vector<double>& acc) {
    int harshEvents = 0;

    for (double a : acc) {
        if (abs(a) > 10.0)  // Threshold for harsh braking / acceleration
            harshEvents++;
    }

    if (harshEvents >= 3)
        return "AGGRESSIVE";

    return "NORMAL";
}

/*
  Generate trip summary
*/
void generateTripSummary(const vector<double>& speed, const vector<double>& acc) {
    double avgSpeed = accumulate(speed.begin(), speed.end(), 0.0) / speed.size();
    double maxSpeed = *max_element(speed.begin(), speed.end());

    cout << "Average Speed: " << avgSpeed << " km/h\n";
    cout << "Max Speed: " << maxSpeed << " km/h\n";
    cout << "Harsh Events: ";

    int cnt = 0;
    for (double a : acc)
        if (abs(a) > 10.0) cnt++;

    cout << cnt << endl;
}

/*
  Main pipeline
*/
int main() {

    // Simulated sensor input
    vector<SensorSample> rawSamples = {
        {20,1},{25,2},{40,3},{60,4},{30,5},
        {80,6},{40,7},{90,8},{30,9},{50,10}
    };

    // STEP 1: Preprocessing
    vector<double> cleanSpeed = preprocessSensorData(rawSamples);

    // STEP 2: Feature extraction
    vector<double> acceleration = computeAcceleration(cleanSpeed);

    // STEP 3: Classification
    string behavior = classifyDrivingPattern(acceleration);

    // STEP 4: Summary
    generateTripSummary(cleanSpeed, acceleration);

    cout << "Driving Pattern: " << behavior << endl;

    return 0;
}