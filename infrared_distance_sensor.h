const float VOLTS_PER_MEASUREMENT = 5.0 / 1024.0;

class infrared_distance_sensor {
  public:
    infrared_distance_sensor(int pin) {
      pinMode(pin, INPUT);
      this->pin = pin;
    }

    float read_distance() {
      float volts = analogRead(this->pin) * VOLTS_PER_MEASUREMENT;
      return pow(14.7737 / volts, 1.2134); // for small IR sensor (SHARP 2Y0A21)
    }

  private:
    int pin;
};
