#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/light_effect.h"
#include "esphome/components/light/light_output.h"
#include "e131_light_effect_base.h"

namespace esphome {
namespace e131 {

class E131LightEffect : public E131LightEffectBase, public light::LightEffect {
 public:
  // Updated to use const char* as required by ESPHome 2025.11.0+
  E131LightEffect(const char *name);

  // Updated return type (ESPHome no longer returns std::string)
  const char *get_name() override;

  void start() override;
  void stop() override;
  void apply() override;

  int32_t get_universe_count() const override;

 protected:
  bool process(int32_t universe, const E131Packet &packet) override;
};

}  // namespace e131
}  // namespace esphome
