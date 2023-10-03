#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/light_effect.h"
#include "esphome/components/light/light_output.h"

namespace esphome {
namespace e131 {

class E131Component;
struct E131Packet;

enum E131LightChannels { E131_MONO = 1, E131_RGB = 3, E131_RGBW = 4 };

class E131LightEffectBase {
 public:
  E131LightEffectBase();

  virtual const std::string &get_name() = 0;

  virtual void start();
  virtual void stop();

  int get_data_per_universe() const;
  int get_lights_per_universe() const;
  int get_first_universe() const;
  int get_last_universe() const;
  virtual int get_universe_count() const = 0;
  bool get_use_brightness() const;

  void set_first_universe(int universe) { this->first_universe_ = universe; }
  void set_channels(E131LightChannels channels) { this->channels_ = channels; }
  void set_e131(E131Component *e131) { this->e131_ = e131; }
  void set_use_brightness(bool use_brightness) { this->use_brightness_ = use_brightness; }

 protected:
  int first_universe_{0};
  int last_universe_{0};
  E131LightChannels channels_{E131_RGB};
  E131Component *e131_{nullptr};
  bool use_brightness_ {false};

  virtual bool process(int universe, const E131Packet &packet) = 0;

  friend class E131Component;
};

}  // namespace e131
}  // namespace esphome
