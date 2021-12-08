#include "Config.h"

namespace impresarioUtils {

std::unique_ptr<Config> Config::instance = nullptr;

Config::Config(std::string &configFilePath) {
    configFile = YAML::LoadFile(configFilePath);
}

Config &Config::getInstance() {
    return *instance;
}

void Config::initialize(std::string &configFilePath) {
    if (instance == nullptr) {
        instance = std::unique_ptr<Config>(new Config(configFilePath));
    } else {
        throw std::logic_error("Attempted to initialize Config singleton more than once");
    }
}

int Config::getInt(const char *name) {
    return configFile[name].as<int>();
}

uint Config::getUint(const char *name) {
    return configFile[name].as<uint>();
}

std::string Config::getString(const char *name) {
    return configFile[name].as<std::string>();
}

float Config::getFloat(const char *name) {
    return configFile[name].as<float>();
}

bool Config::getBool(const char *name) {
    return configFile[name].as<bool>();
}

}
