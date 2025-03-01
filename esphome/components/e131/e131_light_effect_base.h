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

  int32_t get_data_per_universe() const;
  int32_t get_lights_per_universe() const;
  int32_t get_first_universe() const;
  int32_t get_last_universe() const;
  virtual int32_t get_universe_count() const = 0;

  void set_first_universe(int32_t universe) { this->first_universe_ = universe; }
  void set_channels(E131LightChannels channels) { this->channels_ = channels; }
  void set_e131(E131Component *e131) { this->e131_ = e131; }

 protected:
  int32_t first_universe_{0};
  int32_t last_universe_{0};
  E131LightChannels channels_{E131_RGB};
  E131Component *e131_{nullptr};

  virtual bool process(int32_t universe, const E131Packet &packet) = 0;

  friend class E131Component;
};

}  // namespace e131
}  // namespace esphome
